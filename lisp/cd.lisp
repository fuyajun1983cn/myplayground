;;
;; cd 数据库
;;
;;全局变量
(defvar *db* nil)

;;相关操作
(defun make-cd (title artist rating ripped)
  (list :title title :artist artist :rating rating :ripped ripped))

(defun add-record (cd) (push cd *db*))

;;
;; ~a 美化指令，消耗一个实参，然后将其输出为人类可读的形式
;; ~10t 告诉format产生足够的空格，以确保在处理下一个~a时之前
;; 将光标移动10列。 ~t不使用任何实参。
;; ~% 产生一个换行
;;
(defun dump-db ()
  (dolist (cd *db*)
    (format t "~{~a: ~10t~a~%~}~%" cd)))

(defun prompt-read (prompt)
  (format *query-io*  "~a: " prompt)
  (force-output *query-io*)
  (read-line *query-io*))

(defun prompt-for-cd ()
  (make-cd
   (prompt-read "Title")
   (prompt-read "Artist")
   (or (parse-integer (prompt-read "Rating") :junk-allowed t) 0) 
   (y-or-n-p "Ripped [y/n]")))

(defun add-cds ()
  (loop (add-record (prompt-for-cd))
     (if (not (y-or-n-p "Another? [Y/N]: ")) (return))))

;;保存和加载数据库
(defun save-db (filename)
  (with-open-file (out filename
                       :direction :output ;;打开一个用于写的文件
                       :if-exists :supersede);;当存在同名的文件时,覆盖
    (with-standard-io-syntax
      (print *db* out))))

(defun load-db (filename)
  (with-open-file (in filename)
    (with-standard-io-syntax
      (setf *db* (read in))))) ;;setf宏是Commmon Lisp的一个主要赋值操作符,
                               ;;将第一个参数设置为其第二个参数的求值结果.

;;查询数据库
(defun select-by-artist (artist)
  (remove-if-not
   #'(lambda (cd) (equal (getf cd :artist) artist))
   *db*))

(defun select (selector-fn)
  (remove-if-not selector-fn *db*))

(defun artist-selector (artist)
  #'(lambda (cd) (equal (getf cd :artist) artist)))

;;可变数量形参
;;(defun foo (&key a b c))
;;(foo :a 1 :b 2 :c 3) -> (1 2 3)
;;(foo :c 3 :b 2 :a 1) -> (1 2 3)
;;(foo :a 1 :c 3) -> (1 nil 3)
;;(foo) -> (NIL NIL NIL)
;;(defun foo (&key a (b 30) (c 20 c-p)))
;; a,b都有默认值,且如果没有传递c的值的话,c-p还会返回一个boolean值.
;;
(defun where (&key title artist rating (ripped nil ripped-p))
  #'(lambda (cd)
      (and
       (if title (equal (getf cd :title) title) t)
       (if artist (equal (getf cd :artist) artist) t)
       (if rating (equal (getf cd :rating) rating) t)
       (if ripped-p (equal (getf cd :ripped) ripped) t))))

(defun update (selector-fn &key title artist rating (ripped nil ripped-p))
  (setf *db*
        (mapcar
         #'(lambda (row)
             (when (funcall selector-fn row)
               (if title (setf (getf row :title) title))
               (if artist (setf (getf row :artist) artist))
               (if rating (setf (getf row :rating) rating))
               (if ripped-p (setf (getf row :ripped) ripped)))
             row) *db*)))

(defun remove-rows (selector-fn)
  (setf *db* (remove-if selector-fn *db*)))

;;
;;宏
;;

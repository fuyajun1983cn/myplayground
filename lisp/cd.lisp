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
                       :direction :output
                       :if-exists :supersede)
    (with-standard-io-syntax
      (print *db* out))))

(defun load-db (filename)
  (with-open-file (in filename)
    (with-standard-io-syntax
      (setf *db* (read in)))))



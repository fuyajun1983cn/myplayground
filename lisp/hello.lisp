;;
;; Common Lisp测试程序
;; 在SLIME中输入逗号调出菜单
;;
;; 使用 C-c C-l调用slime-load-file来加载文件
;;
;; C-c C-k 来编译并加载当前缓冲区所关联的文件
;;
(defun hello-world()
  "Hello world program."
  (format t "Hello World!"))

(defun say-hello ()
  (print "Please type your name: ")
  (let ((name (read)))
    (print "Nice to meet you, ")
    (print name)))

(defun say-hello2 ()
  (princ "Please type your name: ")
  (let ((name (read-line)))
    (princ "Nice to meet you, ")
    (princ name)))

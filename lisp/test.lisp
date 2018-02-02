;;a test framework

(defvar *test-name* nil)

(defmacro deftest (name parameters &body body)
  "Define a test function. Within a test function we can call
   other test function or use 'check' to run individual test cases."
  `(defun ,name ,parameters
     (let ((*test-name* (append *test-name* (list ',name))))
       ,@body)))

;;(defmacro check (form)
;;  `(result-report ,form ',form))
(defmacro check (&body forms)
  `(combine-results
     ,@(loop for f in forms collect `(result-report ,f ',f))))

;(defmacro with-gensyms ((&rest names) &body body)
; `(let ,(loop for n in names collect `(,n (gensym)))
;    ,@body))

(defmacro combine-results (&body forms)
  (with-gensyms (result)
    `(let ((,result t))
       ,@(loop for f in forms collect `(unless ,f (setf ,result nil)))
       ,result)))

(defun result-report (result form)
  "Report test result."
  (format t "~:[FAIL~;pass~] ... ~a~%" result form)
  result)

(deftest test-+ ()
  (check
    (= (+ 1 2) 3)
    (= (+ 1 2 3) 6)
    (= (+ -1 -3) -4)))

(deftest test-*()
  (check
    (= (* 2 2) 4)
    (= (* 3 5) 15)))

(deftest test-arithmetic()
  (combine-results
    (test-+)
    (test-*)))

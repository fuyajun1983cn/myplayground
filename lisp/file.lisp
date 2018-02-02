(with-open-file (my-stream
                 "testfile.txt"
                 :direction :output  ;; A colon-prepended symbol in Common Lisp always means itself.
                 :if-exists :supersede)
  (princ "Hello File!" my-stream))

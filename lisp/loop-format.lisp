;;
;;Loop and Format
;;
(loop for i
   below 5
   sum i)

;;Counting from a Starting Point to an Ending Point
(loop for i
   from 5
   to 10
   sum i)

;;Iterating Through Values in a List
(loop for i
   in '(100 20 3)
   sum i)

;;doing Stuff in a Loop
(loop for i
   below 5
   do (print i))

;;Doing Stuff Under Certain Conditions
(loop for i
   below 10
   when (oddp i)
   sum i)

;;Breaking out of a Loop Early
(loop for i
   from 0
   do ((format t "~&  ~%")
       i)
   when (= i 5)
   return 'falafel)

;;Collecting a List of Values
(loop for i
   in '(2 3 4 5 6)
   collect (* i i))

;;Using Multiple for Clauses
(loop for x below 10
   for y below 10
   collect (+ x y))




(defrule example-4
    (grocery-list $?list)
    =>
    (printout t "I need to buy " $?list crlf))

(assert (grocery-list eggs milk bacon))

(run)
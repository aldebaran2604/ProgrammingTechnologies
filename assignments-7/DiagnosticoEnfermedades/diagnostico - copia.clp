(reset)

(defrule botulismo 
(colicos) (problema-respiratorio) (problema-habla) (vision-doble) (nauseas) (vomito) (debilidad) (paralisis) 
=>
(printout t "Usted tiene botulismo" crlf))

(assert (colicos))
(assert (problema-respiratorio))
(assert (problema-habla))
(assert (vision-doble))
(assert (nauseas))
(assert (vomito))
(assert (debilidad))
(assert (paralisis))
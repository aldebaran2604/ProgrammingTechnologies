(defrule botulismo 
(colicos) (problema-respiratorio) (problema-habla) (vision-doble) (nauseas) (vomito) (debilidad) (paralisis) 
=>
(printout t "Usted tiene botulismo" crlf))

(defrule colera 
(diarrea) (vomito) (deshidratacion)
=>
(printout t "Usted tiene Cólera" crlf))

(defrule lepra 
(insensibilidad-piel) (insensibilidad-dolor) (vomito) (deshidratacion)
=>
(printout t "Usted tiene Cólera" crlf))
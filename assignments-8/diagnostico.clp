(defrule botulismo 
(colicos) (problema-respiratorio) (problema-habla) (vision-doble) (nauseas) (vomito) (debilidad) (paralisis) 
=>
(store "enfermedad" "Usted tiene botulismo"))
;(printout t "Usted tiene botulismo" crlf))

(defrule colera 
(diarrea) (vomito) (deshidratacion)
=>
(store "enfermedad" "Usted tiene Cólera"))
;(printout t "Usted tiene Cólera" crlf))

(defrule lepra 
(insensibilidad-piel) (insensibilidad-dolor) (vomito) (deshidratacion)
=>
(store "enfermedad" "Usted tiene lepra"))
;(printout t "Usted tiene lepra" crlf))

(defrule dengue 
(fiebre) (dolor-articular) (dolor-muscular) (inflamacion-ganglios) (erupcion-piel)
=>
(store "enfermedad" "Usted tiene Dengue"))
;(printout t "Usted tiene Dengue" crlf))

/*
asserts para botulismo
(assert (colicos))
(assert (problema-respiratorio))
(assert (problema-habla))
(assert (vision-doble))
(assert (nauseas))
(assert (vomito))
(assert (debilidad))
(assert (paralisis))
*/

/*
asserts para colera 
(assert (diarrea))
(assert (vomito))
(assert (deshidratacion))
*/

/*
asserts para lepra 
(assert (insensibilidad-piel))
(assert (insensibilidad-dolor))
(assert (vomito))
(assert (deshidratacion))
*/

/*
asserts para dengue 
(assert (fiebre))
(assert (dolor-articular))
(assert (dolor-muscular))
(assert (inflamacion-ganglios))
(assert (erupcion-piel))
*/
(store "enfermedad1" "")
(store "enfermedad2" "")
(store "enfermedad3" "")
(store "enfermedad4" "")
(defrule botulismo 
(colicos) (problema-respiratorio) (problema-habla) (vision-doble) (nauseas) (vomito) (debilidad) (paralisis) 
=>
(store "enfermedad1" "Usted tiene botulismo"))
;(printout t "Usted tiene botulismo" crlf))

(defrule colera 
(diarrea) (vomito) (deshidratacion)
=>
(store "enfermedad2" "Usted tiene Cólera"))
;(printout t "Usted tiene Cólera" crlf))

(defrule lepra 
(insensibilidad-piel) (insensibilidad-dolor) (vomito) (deshidratacion)
=>
(store "enfermedad3" "Usted tiene lepra"))
;(printout t "Usted tiene lepra" crlf))

(defrule dengue 
(fiebre) (dolor-articular) (dolor-muscular) (inflamacion-ganglios) (erupcion-piel)
=>
(store "enfermedad4" "Usted tiene Dengue"))
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
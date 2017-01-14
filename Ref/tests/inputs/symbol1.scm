

(and (not (symbol? 5)) (not (symbol? "141")) (eq? 'liel (string->symbol "liel"))
  (eq? "doo" (symbol->string 'doo))
)

#! /usr/bin/petite --script

(load "../compiler.scm" )

(let* (
		(fileA (readSexprs "results.txt"))
		(a   (display fileA))
		(C   (display "\n"))
		(fileB (readSexprs "expectedResults.txt"))
		(b   (display fileB))		
		(D   (display "\n"))
		(results (map (lambda (x y) (if (equal? x y) #t #f)) fileA fileB)) 
		(resultsFilter (filter (lambda (x) (not (equal? #t x))) results))
		(doubleResults	(map (lambda (x y) (display x) (display "\t\t\t") (display y) (display "\n")) fileA fileB))
	)
	(display "Results : \n")
	(display results)
	(display "\n Failed : \n")
	(display resultsFilter)
	(display "\n")
)
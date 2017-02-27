for f in $(ls -v tests/*.scm); do 
  echo "Doing test $f:"
  echo "--------------------------------"
  echo "(load \"compiler.scm\") (compile-scheme-file \"$f\" \"out_test.c\")" | scheme -q
  gcc -o out_test out_test.c
  our=`./out_test`
  chez=`cat $f | scheme -q`
  result=""
  if [ "$our" = "$chez" ]; then
    result="#t"
  else
    result=`echo "(equal? '$our '$chez)" | scheme -q`
  fi
  
  if [ "$result" = "#t" ]; then 
      echo "Test $f Passed"
  else
      echo "*** RESULTS DIFFER in $f"
      echo "*** scheme output: $chez"
      echo "*** our output: $our"
  fi
  echo "--------------------------------"
  echo
done

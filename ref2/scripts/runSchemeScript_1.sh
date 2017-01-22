#! /usr/bin/petite --script

(load "../compiler.scm" )
(compile-scheme-file "all_tests.scm" "../out.c")
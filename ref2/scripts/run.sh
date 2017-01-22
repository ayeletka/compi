#/bin/bash

rm ../out.c
rm ../out

./runSchemeScript_1.sh

cd ../
make
./out > scripts/results.txt
cd scripts

./runSchemeScript_2.sh
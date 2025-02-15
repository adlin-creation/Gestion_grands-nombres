#!/bin/bash

ERROR=0

echo "Vérification mémoire"

for TEST in *_tableau *_bigint
do
	if [ $TEST = "11_bigint" ]
	then
		valgrind --tool=memcheck --quiet --error-exitcode=1 ./$TEST > /dev/null 2>&1 < deux
	else
		valgrind --tool=memcheck --quiet --error-exitcode=1 ./$TEST > /dev/null 2>&1
	fi
	RET=$?
	if [ $RET -eq 0 ]
	then 
		echo -e "\t$TEST \xE2\x9C\x94"
	else
		echo -e "\t$TEST"
	fi
        ERROR=$(( ERROR + $RET ))
done

echo -e "\tTotal erreurs/fuites mémoire : $ERROR"

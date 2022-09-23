#!/bin/bash
PIDARRAY=()
for i in `seq 1 3`
do
	md5sum parallel.sh &	
	PIDARRAY+=("$!")
done
wait ${PIDARRAY[@]}

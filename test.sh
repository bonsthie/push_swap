#!/bin/bash
i=0
for (( c=1; c<=$2; c++ ))
do
    k=$(./push_swap $(shuf -n $1 -i 0-100000) | wc -l)
    if [ $k -gt $3 ]
    then
        i=$((i+1))
        echo $k
    fi
done
echo $i

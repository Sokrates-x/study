#!/bin/bash

## enable line no. when debug
old_ps4=$PS4
PS4='$LINENO: '
export PS4

var[1]="AA"
var[2]="BB"
var[3]="CC"

for i in $(seq 1 3)
do
	echo ${var[i]}
done

echo ${var[1]}
echo ${var[2]}
echo ${var[3]}

a=${var[*]}
echo $a

b=${var[@]}
echo $b

# begin debug
set -x

# arry size
echo ${#var[@]}

# end debug
set +x

# str size
word=xiedong
echo ${#word}

declare -A ass
ass[RAII]="Resource Acquire Is Initialization."
ass[IMPL]="Implementation"

echo ${!ass[*]}

PS4=$old_ps4
export PS4

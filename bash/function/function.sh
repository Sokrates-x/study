#!/bin/bash

path=$PATH

prepend() {
	[ -d $1 ] && path=$path:$1
}
prepend /tmp
echo $path


dft=${dft-0}
echo $dft
dft=${dft+3}
echo $dft

trivil () {
	for i in $(seq 1 $#)	
	do
		eval echo $@
	## pay attention to shift
	shift
	done
}

trivil_ () {
	for item in $*
	do
		echo $item
	done
}

trivil__ () {
	for item in $@
	do
		echo $item
	done
}

trivil hello world shell script
trivil_ hello world shell script
trivil__ hello world shell script

sum () {
	declare -i sum=0			
	for i in $(seq 1 $#)
	do
		let sum=sum+$1
		shift
	done
	echo $sum
}

sum 1 2 3 4 5 6 

echo "Enter your username:"
# 4 is only limits not request
#read -n 4 username

echo "Enter your passwd:"
#read -s passwd

echo $username
echo $passwd

repeat () {
	while true;
	do
		$@ && return;		
	done
}

declare -i num=3

think_twice ()
{
	echo thinking...
	let num--
	if [ $num -eq 0 ];
	then
		return;
	else
		return -1;
	fi
}

repeat think_twice

for letter in {a..z};
do
	echo $letter
done

beg=0
until [ $beg -eq 10 ];
do
	echo $beg
	let beg++
done


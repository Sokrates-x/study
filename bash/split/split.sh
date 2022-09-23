#!/bin/bash
# use alpha as filename
split -b 1k data.o

# -d use digit as filename
split -b 1k data.o -d

# -d -a use a bit digit as filename
split -b 1k data.o -d -a 3

rm -rf x*

# csplit
csplit split.sh /#/ -n 2 -s {*} -f spt -b "%02d.log"

rm -rf spt*

#!/bin/bash
echo hello | tr l L
# last l is ignored
echo hello | tr l LL
# repeat last l
echo hello | tr ll L

# seq
echo "What's Your Passwd?" |  tr 'a-z' 'A-Z'

# enpy 
echo 12345 | tr '0-9' '9876543210'

# ROT13
echo "hello world" | tr 'a-zA-Z' 'n-za-mN-ZA-M'
echo "hello world" | tr 'a-zA-Z' 'n-za-mN-ZA-M' | tr 'a-zA-Z' 'n-za-mN-ZA-M'

# another form
tr '\n' ' ' < tr.sh
echo

# delete
echo -e "xxaxx" |  tr -d a
# delete except x
echo "xxaxx\n" |  tr -d -c 'x\n'
echo -e "xxaxx" |  tr -d x
# delete except a
echo "xxaxx\n" |  tr -d -c 'a\n'

# -c
echo "Hello World\n" | tr -c 'A-Z\n' '*'

# compress 
echo xxxx | tr -s x

# take calc
# only int
echo $[ 1 + 2 ]
echo $[ $(tr '\n' '+' < sum.txt ) 0 ]
# mixed with alpha
echo $[ 0 $(tr -d 'a-zA-Z' < sum_mix.txt | tr '\n ' '+' | tr -s + ) 0 ]

set -x
# regular express
# digit or alpha
echo abc123 | tr -d [:alnum:]
echo abc123 | tr -d [:alpha:]
echo abc123 | tr -d [:digit:]
echo abc123 | tr -d [:cntrl:]
echo
echo abc123 | tr -d [:graph:]
echo abc123 | tr -d [:lower:]
# printable
echo abc123 | tr -d [:print:]
# , . ...
echo abc123 | tr -d [:punct:]
echo abc123 | tr -d [:space:]
echo
echo abc123 | tr -d [:upper:]
# 0-9a-fA-F
echo abc123 | tr -d [:xdigit:]
set +x

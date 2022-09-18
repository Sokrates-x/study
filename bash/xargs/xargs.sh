#!/bin/bash

# -n  
cat example
cat example | xargs
cat example | xargs -n 2
cat example | xargs -n 3
cat example | xargs -n 4

# -d
echo "aXbXcXdXe" | xargs -d X
echo "aXbXcXdXe" | xargs -d X -n 2

# -0 means splited by NULL
# always use with print0
find * -print0 | xargs -0

./cecho.sh a b c

cecho () {
	echo $* '#'
}

cecho a b c

# addtional cmd
echo -e "arg1\narg2\narg3" | xargs -n 1 ./cecho.sh
#echo -e "arg1\narg2\narg3" | xargs -n 1 cecho

# -I
echo -e "arg1\narg2\narg3" | xargs -I {} ./cecho.sh -p {} -l

# with find
find . -name "*.sh" -print0 | xargs -0 wc -l

# just like while
find . -name "*.sh" -print | (while read arg; do echo $arg; done)
find . -name "*.sh" -print | xargs -I {} echo {}

# ()
ls >> log | (cd ..; ls >> log) | ls >> log

cat log

echo "################################################################################"
# ! means not
find . ! -name "*.sh" -type f | xargs -I ^ sh -c "echo -ne '\n ^: '; grep 3 ^"
echo "################################################################################"
find . ! -name "*.sh" -type f | xargs -I {} sh -c "echo -ne '\n {}: '; grep 3 {}"

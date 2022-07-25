#!/bin/bash

echo "CMD to Manage Files & Directories:"

ls --color=auto
touch a
cp a b
rm a b

touch a
mkdir -p d 
mv a d 

cd d
rename a b *

cd ..
rm -rf d

dirname /etc/bashrc
basename /etc/bashrc

cat a.sh
tac a.sh
nl a.sh
more a.sh
less a.sh
head -n 3 a.sh
tail -n 10 a.sh
od a.sh

#chattr
#lsattr

umask

#set UID rwsr-xr-x 4
#set GID rwxr-sr-x 2
#SBit              1 
mkdir a
chmod 7777 a 

file a.sh
which ip
history
whereis ls
#locate -l 5 passwd
#updatedb
find a.sh

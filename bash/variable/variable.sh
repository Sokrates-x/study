#!/bin/bash

declare -i var
var=0
echo $var
echo ${var}

if [ $var -eq 0 ];
then
echo "var is not abc"
fi

path=$PATH
echo $path
# delete shortest first match
#path=${path#*local/bin:}
# delete longest first match
#path=${path##*local/bin:}
# delete shortest last match
#path=${path%:/usr*bin}
# delete longest last match
#path=${path%%:/usr*bin}
#echo $path

pwd=$PWD
echo childpath
echo ${pwd##/*/}
echo rootpath
echo ${pwd%/*}

mess=143dfdet4w325412etg564433eryt3144esretry34234566dsfery
echo $mess
echo ${mess/1*5/a}
echo ${mess//1*5/a}


# Test and opt
tst=test
opt=delete

## Base if tst exists not null
#echo ${tst-del}
#echo ${tst+del}
#echo ${tst=del}
#echo ${tst?del}
#
## Base if tst not exists
#echo ${ntst-del}
#echo ${ntst+del}
#echo ${ntst=del}
#echo ${ntst?del}
#
#nltst=""
## Base if tst extist null
#echo ${nltst-del}
#echo ${nltst+del}
#echo ${nltst=del}
#echo ${nltst?del}
#
## : if tst exists not null
#echo ${tst:-del}
#echo ${tst:+del}
#echo ${tst:=del}
#echo ${tst:?del}
#
## : if tst not exists
#echo ${ntst:-del}
#echo ${ntst:+del}
#echo ${ntst:=del}
#echo ${ntst:?del}
#
## : if tst extist null
#echo ${nltst:-del}
#echo ${nltst:+del}
#echo ${nltst:=del}
#echo ${nltst:?del}

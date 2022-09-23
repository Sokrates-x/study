#!/bin/bash
# trait filename
file_jpg="abc.jpg"
name=${file_jpg%.*}
echo $name

# trait  
exten=${file_jpg#*.}
echo $exten

# %% 
web="www.baidu.com"
server=${web%%.*}
domain=${web%.*}
domain=${domain#*.}
suffix=${web##*.}
echo $server
echo $domain
echo $suffix

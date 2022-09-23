#!/bin/bash
count=1
for img in `find . -iname '*.jpg' -o -iname '*.png' -type f`
do
	new=image-$count.${img##*.}
	echo "Renaming $img to $new"
	mv $img $new
	let count++
done

for img in `find . -iname '*.jpg' -o -iname '*.png' -type f`
do
	rename image img $img
done

find * -exec rename - _ {} \;

find * | xargs -I {} -exec rename _ + {}

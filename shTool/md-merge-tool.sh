#!/bin/bash

insertPosition=`cat -n CHANGES.md|grep 'API file name #2'|head -1|awk '{print $1}'`

# push merge context to file $2.back
index=-3
cat $3 | while read line
do
  echo "${line}" >> $2.back
  index=$((index + 1))
  if [ $index == $insertPosition ]; then
    # put diff context: $2 - $1 + $3 to $2.back
    diff $1 $2 --ignore-space-change --unchanged-line-format="" --new-line-format="%L" >> $2.back
  fi
done

# let $2 be $2.back
mv $2.back $2
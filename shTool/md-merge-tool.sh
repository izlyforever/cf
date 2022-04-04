#!/bin/bash

insertPosition=`cat -n CHANGES.md|grep 'API file name #2'|head -1|awk '{print $1}'`

# push merge context to file $2.back
index=-3
cat $3 | while read line
do
  index=$((index + 1))
  if [ $index == $insertPosition ]; then
    if [ -n "$line$" ]; then
      printf "\n" >> $2.back
    fi
    # put diff context: $2 - $1 + $3 to $2.back
    diff $1 $2 --ignore-space-change --unchanged-line-format="" --new-line-format="%L" >> $2.back
  fi
  echo "${line}" >> $2.back
done

# let $2 be $2.back
mv $2.back $2

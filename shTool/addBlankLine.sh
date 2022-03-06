#!/bin/bash

addBlackLine() {
  for it in `ls $1`; do
    x=$1"/"$it
    if [ -d $x ]; then
      addBlackLine $x ${@:2}
    else
      xe=${x##*.}
      for ex in ${@:2}; do
        if [ $xe == $ex ] && [ -n "`tail -n 1 $x`" ]; then
          printf "\n" >> $x
        fi
      done
    fi
  done
}

delBlackLine() {
  for it in `ls $1`; do
    x=$1"/"$it
    if [ -d $x ]; then
      delBlackLine $x ${@:2}
    else
      xe=${x##*.}
      for ex in ${@:2}; do
        if [ $xe == $ex ]; then
          while [ -s $x ] && [ -z "`tail -n 1 $x`" ]; do
            sed -i '' -e '$ d' $x
          done
        fi
      done
    fi
  done
}

addBlackLine $@
delBlackLine $@

# example: ./addBlankLine ../ h hpp cpp md py

#!/bin/bash

listAllFile() {
  for it in `ls $1`
  do
    echo $it
    if [[ -f "$it" ]]; then
      echo $it
    fi
    if test -d $it
    then
      listAllFile $it
    fi
  done
}

listAllFile $1

# for file in ../*
# do
#     if test -f $file
#     then
#         echo $file 是文件
#     fi
#     if test -d $file
#     then
#         echo $file 是目录
#     fi
# done

# list_alldir(){
#     for file2 in `ls -a $1`
#     do
#         if [ x"$file2" != x"." -a x"$file2" != x".." ];then
#             if [ -d "$1/$file2" ];then
#                 echo "$1/$file2"
#                 list_alldir "$1/$file2"
#             fi
#         fi
#     done
# }

# list_alldir
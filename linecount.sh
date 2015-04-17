#!/usr/bin/bash

sum=0
for i in $(ls *.cpp *.h); do sum=$(( sum + $(cat $i | wc -l))); echo $i - $(cat $i | wc -l); done
echo $sum

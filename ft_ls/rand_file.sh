#!/bin

for i in `seq $1 $2`
do
dd if=/dev/zero of=./$i bs=512 count=1
done

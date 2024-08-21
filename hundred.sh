#!/bin/bash
echo "Enter a limit"
read num
((for i=1;i<num;i++))
do
echo $i
done
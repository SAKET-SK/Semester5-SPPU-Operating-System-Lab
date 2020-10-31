#!/bin/bash
echo -e "\nProgram Name :- $0
	 \nNo. of Args :- $#
	 \nArgs :- $*
	 \nPattern is :- $1
	 \nFile to search :- $2"
grep $1 $2>abc
if [ $? -ne 0 ]
then
	echo "Pattern not found!"
else
	echo "Pattern found"
	cat abc
fi

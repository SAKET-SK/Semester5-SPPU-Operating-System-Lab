#!/bin/sh
echo -e "\nEnter pattern to search in file :- "
read pat
echo -e "\nEnter file name to search :- "
read fname

if grep $pat $fname
then
	echo pattern found in file!
else
	echo pattern not found!
fi

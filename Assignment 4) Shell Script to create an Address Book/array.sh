#!/bin/bash

echo -e "\nEnter the number of elements to sort:- "
read n

echo -e "\n Enter elements:- "

for((i=0;i<n;i++))
{
	read arr[i]
}


for((i=n-1;i>=0;i--))
{
 	do
		for((j=0;j<i;j++))
	  	do
	   		x=`expr $j + 1`
			if [ ${arr[j]} -gt ${arr[x]} ]
			then
				temp=${arr[j]} 
				arr[$j]=${arr[x]}
				arr[$x]=$temp
			fi
		done
  	done
}

echo -e "\nSorted elements are:- "

for((i=0;i<n;i++))
{
	echo -e "${a[i]}"
}
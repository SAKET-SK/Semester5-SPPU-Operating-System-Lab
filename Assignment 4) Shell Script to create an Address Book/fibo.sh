#!/bin/bash
echo "How many elements to be displayed in fibo :- "
read n

f0=0
f1=1
echo $f0
echo $f1
i=2
while [ $i -le $n ]
do
	f2= expr $f0 + $f1
	
	echo $f2
	
	f0=$f1
	f1=$f2
	
	i= expr $i + 1
done

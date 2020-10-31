#Write a program to implement an address book with options given below: 
#a) Create address book.  
#b) View address book.  
#c) Insert a record.  
#d) Delete a record. 
#e) Modify a record. f) Exit. 
#!/bin/bash 
 
createAddressBook() 
{ 
	if [ -e addressbook.txt ]  
	then 
		echo "Address book is already created" 
	else 
		touch addressbook.txt 
	echo "Wel-come address book " 
	 
	fi 
} 
 
insertRecord() 
{ 
	while true 
	do 
	 
	echo "To add a record in address book please insert record in this format " 
	echo "format: \"Last name,first name,email,phone number\"(no quotes or spaces)." 
	echo "Example: Gaitonde,Ganesh,ganesh@gmail.com,986035" 
	echo "to quit press 'q'." 
	read aInput 
 
	if [ "$dInput" == 'q' ] 
	then 
		break 
	fi 
 
	echo "$aInput" >> addressbook.txt	 
	echo "Record Inserted" 
	if [ "$aInput"=="q" ] 
	then 
		break 
	fi 
	done 
 
} 
 
viewRecord() 
{ 
while true 
do 
	echo "To display a record, enter the last name of person (case sensitive)" 
	read dInput 
	if [ "$dInput" == 'q' ] 
	then 
		break 
	fi 
	echo "Display record $dInput:" 
	grep "$dInput" addressbook.txt 
	RETURNSTATUS=`echo $?` 
	if [ $RETURNSTATUS -eq 1 ] 
	then 
	echo "NO record found" 
	fi 
done 
} 
searchRecord() 
{ 
while true 
do 
	echo "To search a record, enter the last name of person (case sensitive)" 
	read dInput 
	if [ "$dInput" == 'q' ] 
	then 
		break 
	fi 
	echo "Display record $dInput:" 
	grep "$dInput" addressbook.txt 
	RETURNSTATUS=`echo $?` 
	if [ $RETURNSTATUS -eq 1 ] 
	then 
	echo "NO record found" 
	fi 
done 
} 
deleteRecord() 
{ 
	while true 
do 
	echo "To Delete a record, enter the last name of person or email (case sensitive)" 
	echo "if finished then , press 'q' to quit"	 
	read rInput 
	if [ "$rInput" == 'q' ] 
	then 
		break 
	fi 
	echo "Display record $dInput:" 
	grep -n "$rInput" addressbook.txt 
	RETURNSTATUS=`echo $?` 
	if [ $RETURNSTATUS -eq 1 ] 
	then 
	echo "NO record found" 
	else 
 
	echo "Enter line no to remove" 
	read lineNumber 
	for line in `grep -n "$rInput" addressbook.txt` 
	do 
		 
		number=`echo $line|cut -c1` 
		echo $number 
		if [ $number -eq $lineNumber ] 
		then 
		lineRemove="${lineNumber}d" 
		sed -i -e "lineRemove" addressbook.txt 
		echo "The record was remove from the address book." 
		fi 
	done 
	fi 
done 
		 
} 
 
 
while true 
do 
echo "address book?" 
echo "Enter your choice" 
echo "1-->Create address book" 
echo "2-->Insert Record" 
echo "3-->View Record" 
echo "4-->Search Record" 
echo "5-->Delete Record" 
echo 
read input 
case $input in 
1) createAddressBook;; 
2) insertRecord;; 
3) viewRecord;; 
4) searchRecord;; 
5) deleteRecord;; 
esac 
if [ "$input"=='q' ] 
then 
	break 
fi 
done 

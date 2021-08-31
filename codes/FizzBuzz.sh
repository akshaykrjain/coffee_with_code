#!/bin/bash
#Author- Akshay Jain
#FizzBuzz in Bash Script

n=1
while [ $n -le 100 ]
do
  if [[ 0 -eq "($n%3) + ($n%5)" ]] 
  then
  # Check if number is divisible by both 3 & 5 #
    echo "Fizz Buzz"
  elif [[ 0 -eq "($n%5)" ]]
  then
  # Check if number is divisible by 5 #   
    echo "Buzz"
  elif [[ 0 -eq "($n%3)" ]]
  then
  # Check if number is divisible by 3 #
    echo "Fizz"
   else
    echo "$n"
   fi	
  n=$(( $n + 1 ))
done

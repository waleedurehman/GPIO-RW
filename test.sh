#!/usr/bin/env bash


./toggle nonsense &> /dev/null
return=$?
if [ $return == 1 ] 
then
  echo "PASSED: Invalid Input Leads to EXIT STATUS 1"
else
  echo "FAILED: INVALID Input OK"
fi


./toggle --pin nonsense &> /dev/null
return=$?
if [ $return == 1 ] 
then
  echo "PASSED: Inavlid Input Leads to EXIT STATUS 1"
else
  echo "FAILED: INVALID Input OK"
fi

for num in {17..27..5}
do
  ./toggle --pin $num nonsense &> /dev/null
  return=$?
  if [ $return == 1 ] 
  then
    echo "PASSED: Inavlid Input Leads to EXIT STATUS 1"
  else
    echo "FAILED: Invalid Input OK"  
fi
done 

for num in {17..27..5}
do
  ./toggle --pin $num --set nonsense &> /dev/null
  return=$?
  if [ $return == 1 ] 
  then
    echo "PASSED: Inavlid Input Leads to EXIT STATUS 1"
  else
    echo "FAILED: Invalid Input OK"
  fi
done

for num in {17..27..5}
do
  ./toggle --pin $num --set &> /dev/null
  return=$?
  if [ $return == 1 ] 
  then
    echo "PASSED: Inavlid Input Leads to EXIT STATUS 1"
  else
    echo "FAILED: Invalid Input OK"
  fi
done


for num in {17..27..5}
do
  ./toggle --pin $num --set 1 nonsense &> /dev/null
  return=$?
  if [ $return == 1 ] 
  then
    echo "PASSED: Inavlid Input Leads to EXIT STATUS 1"
  else
    echo "FAILED: Invalid Input OK"  
  fi
done 

for num in {17..27..5}
do
  ./toggle --pin $num --set 0 nonsense &> /dev/null
  return=$?
  if [ $return == 1 ] 
  then
    echo "PASSED: Inavlid Input Leads to EXIT STATUS 1"
  else
    echo "FAILED: Invalid Input OK"
  fi
done 

for num in {17..27..5}
do
  ./toggle --pin $num --read nonsense &> /dev/null
  return=$?
  if [ $return == 1 ] 
  then
    echo "PASSED: Inavlid Input Leads to EXIT STATUS 1"
  else
    echo "FAILED: Invalid Input OK"
  fi
done 

for num in {17..27..5}
do
  sudo ./toggle --pin $num --set 1 &> /dev/null
  if [ "`sudo ./toggle --pin $num --read`" == "1" ]
  then
    echo "PASSED: Setting pin $num to 1"
  else
    echo "FAILED: Setting pin $num to 1"
  fi

  sudo ./toggle --pin $num --set 0 &> /dev/null
  if [ "`sudo ./toggle --pin $num --read`" == "0" ]
  then
    echo "PASSED: Setting pin $num to 0"
  else
    echo "FAILED: Setting pin $num to 0"
  fi
done     

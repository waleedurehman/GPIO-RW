#!/usr/bin/env bash

if [ $1 == "B100" ]
then
  pin=22;
elif [ $1 == "C50" ]
then
  pin=27;
elif [ $1 == "E3" ]
then
  pin=17;
else
  echo "No such device"
fi

if [ "`sudo ./toggle --pin $pin --read`" == "0" ]
then
  echo "Rebooting the Device"
  sudo ./toggle --pin $pin --set 1
  if [ "`sudo ./toggle --pin $pin --read`" == "1" ]
  then
    sleep 5
    sudo ./toggle --pin $pin --set 0
    if [ "`sudo ./toggle --pin $pin --read`" == "0" ]
    then
      echo "Reboot Successful"
    fi
  fi
fi


if [ "`sudo ./toggle --pin $pin --read`" == "1" ]
then
  echo "Already off"
  sleep 1
  echo "Turning ON"
  sleep 1
  sudo ./toggle --pin $pin --set 0
  echo "Turned ON"
fi



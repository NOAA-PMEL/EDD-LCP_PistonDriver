## Author : Basharat, Basharat
## Email  : Basharat.martin@noaa.gov
## date	  : 11/25/2022

#!/bin/bash

## check root
if [ $(id -u) -ne 0 ]
then 
	echo "Please run with sudo permission !"
	exit
fi

USER=$(echo $SUDO_USER)

## check if msp430-gcc.tar.gz file exists
if [ -f "./msp430-gcc.tar.xz" ]
then 
	echo "msp430-gcc.tar.xz found"
else
	echo "msp430-gcc.tar.xz NOT found"
	exit
fi

## extract msp430-gcc tar file 
echo "Extracting msp430-gcc.tar.xz file ..."
tar xf ./msp430-gcc.tar.xz -C ./
chown $USER:$USER -R ./msp430-gcc

## copy libmsp430.so file to the /usr/local/lib/
echo "Copying libmsp430.so file to /usr/local/lib ..."
cp ./msp430-gcc/libmsp430/libmsp430.so /usr/local/lib/
sleep 1

## install required packages
echo "Updating the repositories ..."
apt -qq update
sleep 1
apt install -y libboost-filesystem1.71.0 libboost-chrono1.71.0 libboost-thread1.71.0 libusb-1.0-0 libudev1
sleep 1

PWD=$(pwd)

## export the GCC PATH
echo "Exporting GCC PATH into .bashrc file ..."

echo "export PATH=\"$PWD/msp430-gcc/bin:\$PATH\"" >> /home/$USER/.bashrc
echo "export LD_PRELOAD=\"/usr/local/lib/libmsp430.so\"" >> /home/$USER/.bashrc
echo "export GCC_MSP_ROOT=\"$PWD/msp430-gcc\"" >> /home/$USER/.bashrc

echo "completed"
sleep 1
echo "\n"
echo "Please run the command: \"source ~/.bashrc\""
echo "\n"


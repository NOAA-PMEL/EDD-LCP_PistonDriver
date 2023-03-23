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
su $USER -c "tar xf ./msp430-gcc.tar.xz -C ../"

## copy libmsp430.so file to the /usr/local/lib/
echo "Copying libmsp430.so file to /usr/local/lib ..."
cp ../msp430-gcc/libmsp430/libmsp430.so /usr/local/lib/
sleep 1

## install required packages
echo "Updating the repositories ..."
apt -qq update
sleep 1
apt install --no-install-recommends -y libusb-dev libusb-0.1-4 libudev-dev make build-essential g++ libreadline-dev libncursesw5
sleep 1

## compile mspdebug (Flasher)
echo "Git cloning mspdebugger ..."
su $USER -c "git clone https://github.com/dlbeer/mspdebug.git"
su $USER -c "mv mspdebug ../"
echo "Compiling mspdebugger ..."
sleep 1
su $USER -c "make -C ../mspdebug/"
su $USER -c "cp ../mspdebug/mspdebug ../msp430-gcc/bin/msp430-elf-debug"

PWD=$(pwd)

## export the GCC PATH
echo "Exporting GCC PATH into .bashrc file ..."

if [ $(grep -r "GCC_MSP_ROOT" /home/$USER/.bashrc > /dev/null; echo $?) -eq 0 ]
then 
	echo "GCC PATH already present"
else
	echo "export PATH=\"$PWD/../msp430-gcc/bin:\$PATH\"" >> /home/$USER/.bashrc
	echo "export LD_PRELOAD=\"/usr/local/lib/libmsp430.so\"" >> /home/$USER/.bashrc
	echo "export GCC_MSP_ROOT=\"$PWD/../msp430-gcc\"" >> /home/$USER/.bashrc
fi

echo "Removing unnecessary files ..."
sleep 1
su $USER -c "rm -rf ../mspdebug"

echo "Checking if a user in the dialout group ..."
if [ $(groups $USER | grep dialout >/dev/null; echo $?) -eq 0 ]
then
	echo "User in already in the dialout group ..."
	LOGOUT_WARNING=0
else
	echo "User is not in the dialout group, Adding into the dialout group ..."
	usermod -a -G dialout $USER
	LOGOUT_WARNING=1
fi
sleep 1

echo "completed"
sleep 1
echo "\n"
echo "Please run the command: \"source ~/.bashrc\""
echo "\n"

if [ $LOGOUT_WARNING -eq 1 ]
then
	echo "Please log out and log in again to activate user to dialout group"
fi


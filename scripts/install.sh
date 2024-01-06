#!/bin/bash
# Quick C (install.sh)
# A quick C and C++ runner
# Github: https://www.github.com/lewisevans2007/quickc
#
# Install script for quickc

echo "_______       _____      ______      _________"
echo "__  __ \___  ____(_)________  /__    __  ____/"
echo "_  / / /  / / /_  /_  ___/_  //_/    _  / "    
echo "/ /_/ // /_/ /_  / / /__ _  ,<       / /___   "
echo "\___\_\\__,_/ /_/  \___/ /_/|_|      \____/   "

echo "Wecome to the Quick C installer!"
echo "This script will install Quick C to your system."
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

echo "Checking for binary..."
if [ -f quickc ]; then
    echo "Binary found!"
else
    echo "Binary not found!"
    echo "Please download the binary from the releases page and place it in the same directory as this script."
    exit
fi

echo "Checking for gcc and g++ installation..."
if [ -f /usr/bin/gcc ] && [ -f /usr/bin/g++ ]; then
    echo "gcc and g++ found!"
else
    echo "gcc and g++ not found!"
    echo "Installing gcc and g++..."
    apt-get install gcc g++
fi

echo "Checking for /usr/bin/quickc..."
if [ -f /usr/bin/quickc ]; then
    echo "quickc found!"
    echo "Removing old quickc..."
    rm /usr/bin/quickc
else
    echo "quickc not found!"
fi

echo "Installing quickc..."
cp quickc /usr/bin/quickc

echo "Done!"

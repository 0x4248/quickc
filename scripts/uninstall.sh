#!/bin/bash
# Quick C (install.sh)
# A quick C and C++ runner
# Github: https://www.github.com/0x4248/quickc
#
# uninstall script for quickc

echo "_______       _____      ______      _________"
echo "__  __ \___  ____(_)________  /__    __  ____/"
echo "_  / / /  / / /_  /_  ___/_  //_/    _  / "    
echo "/ /_/ // /_/ /_  / / /__ _  ,<       / /___   "
echo "\___\_\\__,_/ /_/  \___/ /_/|_|      \____/   "

echo "Wecome to the Quick C uninstaller!"
echo "This script will uninstall Quick C to your system."
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

echo "Checking for /usr/bin/quickc..."
if [ -f /usr/bin/quickc ]; then
    echo "quickc found!"
    echo "Removing quickc..."
    rm /usr/bin/quickc
else
    echo "quickc not found!"
fi

echo "Done!"
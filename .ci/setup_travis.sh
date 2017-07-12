#!/usr/bin/env bash

if [[ ${TRAVIS_OS_NAME} == "linux" ]]; then
	
	mkdir -p ~/usr
	PREFIX=`cd ~/usr; pwd`
	
	if [ ! -f $PREFIX/bin/cmake ]; then
		wget https://cmake.org/files/v3.7/cmake-3.7.2-Linux-x86_64.sh
		chmod +x cmake-3.7.2-Linux-x86_64.sh
		./cmake-3.7.2-Linux-x86_64.sh --prefix=$PREFIX --exclude-subdir --skip-license
	fi
	
	export PATH="$PREFIX/bin:$PATH"
	
elif [[ ${TRAVIS_OS_NAME} == "osx" ]]; then

	brew update --quiet
	brew install cln cmake doxygen eigen llvm

fi

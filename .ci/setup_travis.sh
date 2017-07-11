#!/usr/bin/env bash

if [[ ${TRAVIS_OS_NAME} == "linux" ]]; then
	
	if [ ! -f ~/usr/bin/cmake ]; then
		mkdir -p `realpath ~/usr`
		wget https://cmake.org/files/v3.7/cmake-3.7.2-Linux-x86_64.sh
		chmod +x cmake-3.7.2-Linux-x86_64.sh
		./cmake-3.7.2-Linux-x86_64.sh --prefix=`realpath ~/usr` --exclude-subdir --skip-license
	fi
	
	cmake --version
	
elif [[ ${TRAVIS_OS_NAME} == "osx" ]]; then

	brew update --quiet
	brew install cln cmake doxygen eigen llvm

fi

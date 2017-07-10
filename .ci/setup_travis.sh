#!/usr/bin/env bash

if [[ ${TRAVIS_OS_NAME} == "linux" ]]; then

elif [[ ${TRAVIS_OS_NAME} == "osx" ]]; then

	brew update --quiet
	brew install cln cmake doxygen eigen llvm

fi

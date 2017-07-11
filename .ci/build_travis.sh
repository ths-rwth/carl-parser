#!/usr/bin/env bash

pushd .

cd ../
git clone https://github.com/smtrat/carl.git
mkdir -p carl/build
cd carl/build/

cmake -D DEVELOPER=ON -D BUILD_ADDONS=OFF ../ || return 1
make lib_carl || return 1

popd

mkdir build
cd build/

cmake -Dcarl_DIR=`pwd`/../../carl/build ../
make

./test/carl-parser-test

#!/usr/bin/env bash

pushd .

mkdir -p cache/

pushd cache/

if [ ! -d cache/carl ]; then
    if [ ${TRAVIS_BRANCH} == "master14" ]; then
        git clone https://github.com/smtrat/carl.git --branch master14
    else
        git clone https://github.com/smtrat/carl.git
    fi
else
	pushd carl/
	git fetch
	git reset --hard origin/master
	popd
fi

mkdir -p carl/build
pushd carl/build/
cmake -D DEVELOPER=ON -D BUILD_ADDONS=OFF ../ || return 1
if [ ${TRAVIS_BRANCH} == "master14" ]; then
    make lib_carl || return 1
else
    make carl || return 1
fi
popd

popd


mkdir -p build
cd build/

cmake ../ || return 1
make || return 1

# Build a second time to avoid problems in macOS
cmake ../ || return 1
make || return 1

./test/carl-parser-test || return 1

popd

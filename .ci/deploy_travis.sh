#!/usr/bin/env bash

BRANCH="deploy-`git rev-parse --short HEAD`"

echo $BRANCH

git checkout --orphan $BRANCH

git add .gitignore CMakeLists.txt README.md
git add cmake/ resources/ src/ test/
git add build/src/carl-parser/

git commit -m "Prebuild parser"
git push
#!/usr/bin/env bash

BRANCH="deploy-`git rev-parse --short HEAD`"

echo $BRANCH

git remote add github https://${GH_TOKEN}@github.com/smtrat/carl-parser.git

git checkout --orphan $BRANCH

git add .gitignore CMakeLists.txt README.md
git add cmake/ resources/ src/ test/
git add build/src/carl-parser/

git commit -m "Prebuild parser"
git push github $BRANCH
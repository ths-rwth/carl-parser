#!/usr/bin/env bash

if [[ ${TASK} == "deploy" ]]; then

	BRANCH="deploy-`git rev-parse --short HEAD`"
	git checkout --orphan $BRANCH

	git add .gitignore CMakeLists.txt README.md
	git add cmake/ resources/ src/ test/
	git add build/src/carl-parser/

	git commit -m "Prebuild parser"
	git tag -fa deploy-latest

	git remote add github https://${GH_TOKEN}@github.com/smtrat/carl-parser.git
	git push github $BRANCH --tags
fi

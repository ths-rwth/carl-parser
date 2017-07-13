#!/usr/bin/env bash

if [[ ${TASK} == "DEPLOY" ]]; then

	BRANCH="deploy-`git rev-parse --short HEAD`"
	git checkout --orphan $BRANCH

	git add .gitignore CMakeLists.txt README.md
	git add cmake/ resources/ src/ test/
	git add -f build/src/carl-parser/

	git commit -m "Prebuild parser"
	echo "Creating tag"
	git tag -fa deploy-latest -m "latest version"
	echo "Pushing to new remote"
	git remote add github https://${GH_TOKEN}@github.com/smtrat/carl-parser.git
	git push github $BRANCH --tags
fi

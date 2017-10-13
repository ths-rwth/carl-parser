#!/usr/bin/env bash

if [[ ${TASK} == "DEPLOY" ]]; then

	BRANCH="deploy-`git rev-parse --short HEAD`"
	git checkout --orphan $BRANCH

	git add .gitignore CMakeLists.txt README.md
	git add cmake/ resources/ src/ test/
	git add -f lib/
	git add -f src/generated/

	git commit -m "Prebuild parser"
	git tag -fa deploy-latest -m "latest version"

	git remote add github https://${GH_TOKEN}@github.com/smtrat/carl-parser.git
	git push github $BRANCH --tags --force
	
	git for-each-ref --sort=committerdate --format='%(refname:short)'

	git fetch --unshallow
	
	git for-each-ref --sort=committerdate --format='%(refname:short)'

	for branch in `git for-each-ref --sort=committerdate --format='%(refname:short)'`
	do
		# Avoid deleting branches other than deploy-<commitid>
		if [[ ! "$branch" =~ ^origin/deploy-[0-9a-f]+$ ]]; then
			continue
		fi
		
		# Avoid deleting branches referenced by tags
		tags=`git log --oneline --decorate $branch | grep "tag:"`
		if [[ ! -z "$tags" ]]; then
			continue
		fi
		
		# Avoid deleting branches less than a week old
		now=`date +%s`
		lastcommit=`git log --pretty=format:'%at' -1 $branch`
		days=$(((now-lastcommit)/3600/24))
		if [ "$days" -lt 7 ]; then
			continue
		fi
		
		echo "Deleting $branch..."
		git push origin --delete $branch
	done
fi

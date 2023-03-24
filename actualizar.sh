#!/bin/bash
git add .
if [$# -ne 2]; then
	git commit -m $1
else #
	git commit -m date
fi
git push


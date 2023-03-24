#!/bin/bash
now="$(date)"
git add .
if [$1 -ne 2]; then
	git commit -m $1
else 
	git commit -m "$now"
fi
git push


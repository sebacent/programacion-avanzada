#!/bin/bash
now="$(date)"
git add .
if [ -z "$1" ]; then
	git commit -m "$now"
else 
	git commit -m "$1"
fi
git push


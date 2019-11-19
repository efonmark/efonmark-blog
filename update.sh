#!/bin/bash
while true
do
	git reset --hard HEAD
	git pull --rebase
	find -iname *.html | xargs rm
	sleep 600
done
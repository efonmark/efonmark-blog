#!/bin/bash
while true
do
	git reset --hard HEAD
	git pull --rebase
	find -iname *.html | xargs rm
	hexo g
	sleep 3600
done
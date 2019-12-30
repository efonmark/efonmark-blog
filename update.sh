#!/bin/bash
while true
do
	git reset --hard HEAD
	git pull --rebase
	find -iname *.html | xargs rm
	hexo g
	sleep 600
done
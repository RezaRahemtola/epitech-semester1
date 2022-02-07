#!/bin/bash

git pull  # Avoiding problems by pulling first
git add . # Adding all the files 
git commit -m "$1"
git push origin master

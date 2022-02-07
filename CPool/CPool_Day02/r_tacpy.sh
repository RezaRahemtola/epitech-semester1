#!/bin/bash


sed -n 'n;p' | cut -d: -f 1 | rev | sort -r | head -n "$MY_LINE2" | tail -n "$(($((MY_LINE2-MY_LINE1))+1))" | cat -e | sed -e "s/$/, /g" | tr -d "$\n" | sed -e "s/, $/.\n/"

# sed to display 1/2 line starting with the 2nd
# cut only login
# reverse the login
# sort in reverse order
# head + tail to select the right part of the file
# cat + sed + tr to replace \n by commas and spaces
# sed to remove the last comma/space and replace it by a dot and line break

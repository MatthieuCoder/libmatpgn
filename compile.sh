#!/bin/sh

t=`mktemp -d`
cd $t
cat /dev/stdin | pdflatex
cat texput.pdf
cd -
rm -r $t

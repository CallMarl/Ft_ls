#!/bin/zsh

find . -type f -name '*.o~' -delete
find . -type f -name '*.c~' -delete
find . -type f -name '*.h~' -delete
find . -type f -name '*.a~' -delete
find . -type f -name '*.sh~' -delete
find . -type f -name '*.txt~' -delete
find . -type f -name '*.md~' -delete
find . -type f -name 'makefile~' -delete
find . -type f -name 'Makefile~' -delete
find . -type f -name '.gitignore~' -delete
find . -type f -name 'auteur~' -delete
find . -type f -name 'todo~' -delete

find . -type f -name '[._]*.s[a-v][a-z]' -delete
find . -type f -name '[._]*.sw[a-p]' -delete
find . -type f -name '[._]s[a-v][a-z]' -delete
find . -type f -name '[._]sw[a-p]' -delete

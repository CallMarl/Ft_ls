#!/bin/bash

make fclean &>/dev/null

EXT=""
	EXT=$EXT"\.o\~|"
	EXT=$EXT"\.c\~|"
	EXT=$EXT"\.h\~|"
	EXT=$EXT"\.a\~|"
	EXT=$EXT"\.sh\~|"
	EXT=$EXT"\.txt\~|"
	EXT=$EXT"\.md\~"

REG_EXT=""
	REG_EXT=$REG_EXT"[._]*.s[a-v][a-z]|"
	REG_EXT=$REG_EXT"[._]*.sw[a-p]|"
	REG_EXT=$REG_EXT"[._]s[a-v][a-z]|"
	REG_EXT=$REG_EXT"[._]sw[a-p]"

FILE=""
	FILE=$FILE"makefile\~|"
	FILE=$FILE"Makefile\~|"
	FILE=$FILE"\.gitignore\~|"
	FILE=$FILE"todo~"

find -E . -regex "(.*($EXT|$REG_EXT|$FILE))" -delete

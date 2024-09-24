#!/bin/sh

# Gets all the files in the current directory and adds the corresponding field in the Makefile file, if exists.
ft_getmakefilesrcs() {
	RED='\033[0;31m'
    NC='\033[0m'
	if [ ! -f ./Makefile ]; then
		echo "${RED}error: Makefile not found${NC}"
		return 1
	fi
	echo SRCS= | tr -d "\n" >> Makefile && ls -la | grep -v "Makefile" | sed 's/$/ \\/' >> Makefile
}
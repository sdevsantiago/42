#!/bin/sh

# Include manuals path
echo "export MANPATH="$(dirname $(pwd))/docs/*/*/*/man:${MANPATH}"" >> ~/.zshrc
#!/bin/bash

INSTALL_DIR="/usr/local/include"

HEADER_FILE="sort.h"

if [ "$(id -u)" -ne 0 ]; then
    echo "Error: This script must be run with root privileges."
    echo "Please use 'sudo ./install.sh' to run it."
    exit 1
fi

if [ ! -f "$HEADER_FILE" ]; then
    echo "Error: The file '$HEADER_FILE' was not found in the current directory."
    echo "Please run this script from the same directory as '$HEADER_FILE'."
    exit 1
fi

if [ ! -d "$INSTALL_DIR" ]; then
    echo "Creating installation directory: $INSTALL_DIR"
    mkdir -p "$INSTALL_DIR"
    if [ $? -ne 0 ]; then
        echo "Error: Could not create directory $INSTALL_DIR. Check your permissions."
        exit 1
    fi
fi

echo "Copying '$HEADER_FILE' to '$INSTALL_DIR'..."
cp "$HEADER_FILE" "$INSTALL_DIR/"

if [ $? -eq 0 ]; then
    echo "Installation successful!"
    echo ""
    echo "To use the library, simply include it in your C code:"
    echo "#include <sort.h>"
    echo ""
    echo "Then compile your program as usual:"
    echo "gcc your_program.c -o your_program"
else
    echo "Error: Failed to copy the file. Check your permissions or try running with 'sudo'."
    exit 1
fi

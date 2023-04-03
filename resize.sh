#!/bin/bash

if ["$1" == ""]
then
    echo "Must give a file path as an argument."
else
    python3 bonus/resizer.py $1
    echo "File was resized"
    ./my_paint $1
fi

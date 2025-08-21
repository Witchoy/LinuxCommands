#!/bin/bash

for dir in Stage_1 Stage_2 Stage_3 Stage_4 Stage_5; do
    if [ -d "$dir" ]; then
        for command in "$dir"/*; do
            echo "Building in $command ..."
            cd "$command" || continue
            make clean
            make
            mv ./bin/* ../../Final_Builds/
            make clean
            cd - > /dev/null
        done
    else
        echo "Directory $dir does not exist."
    fi
done

echo "All builds completed."

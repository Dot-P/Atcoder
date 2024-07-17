#!/bin/bash

if [ "$#" -lt 1 ]; then
    echo "Error: Not enough arguments"
    exit 1
fi

if [ "$1" = "new" ]; then
    if [ "$#" -lt 3 ]; then
        echo "Error: Not enough arguments for 'new'"
        exit 1
    fi
    path=$(acc config-dir)
    echo "Config directory path: $path" 

    lang="$3"
    IFS=$'\n' directories=($(ls "/${path}" | sed 's#/##'))
    echo "Directories found: ${directories[@]}"  

    match="no"
    for dir in "${directories[@]}"; do
        if [ "$dir" = "$3" ]; then
            match="yes"
            break
        fi
    done

    if [ "$match" = "yes" ]; then
        acc config default-template "$3"
        acc new "$2"
    else
        echo "Error: no template"
    fi
elif [ "$1" = "test" ]; then
    path=$(acc config-dir)
    lang=$(jq -r '.["default-template"]' "${path}/config.json")
    if [ "$lang" = "cpp" ]; then
    echo "C++"
        g++ main.cpp && oj t -d "./sample"
    elif [ "$lang" = "go" ]; then
    echo "Go"
        oj t -d "./sample" -c "go run main.go"
    elif [ "$lang" = "rust" ]; then
    echo "Rust"
        rustc -o a.out main.rs && oj t -d "./sample" -c "./a.out"
    else
        echo "Error: no such language"
    fi
elif [ "$1" = "submit" ]; then
    acc s
else
    echo "Error: no such command"
fi

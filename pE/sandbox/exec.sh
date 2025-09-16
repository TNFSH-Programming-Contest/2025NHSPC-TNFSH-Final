#!/bin/bash

problem_name=rook
sandbox=$(dirname "$0")

"${sandbox}/${problem_name}.exe" "$@"

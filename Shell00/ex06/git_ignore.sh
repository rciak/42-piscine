#!/bin/bash
git status --ignored | grep $'\t' | sed 's/^\t*//g'

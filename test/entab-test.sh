#! /usr/bin/env bash

RESULT=$(echo -e '            foo' | ./out/entab)
echo '12 spaces should result in 3 tabs:'
printf "%q" "${RESULT}"
echo

RESULT=$(echo -e '              foo' | ./out/entab)
echo '14 spaces should result in 3 tabs and 2 spaces:'
printf "%q" "${RESULT}"
echo

RESULT=$(echo -e " \t\t    foo" | ./out/entab)
echo 'Mixed spaces and tabs should result in 3 tabs:'
printf "%q" "${RESULT}"
echo

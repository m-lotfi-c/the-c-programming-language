#! /usr/bin/env bash

RESULT=$(echo -e "\t\t\tfoo" | ./out/detab)
echo '3 tabs should result in 12 spaces'
printf "%q" "${RESULT}"
echo

RESULT=$(echo -e "\t\t\t  foo" | ./out/detab)
echo '3 tabs two spaces should result in 14 spaces:'
printf "%q" "${RESULT}"
echo

RESULT=$(echo -e " \t\t    foo" | ./out/detab)
echo 'Mixed spaces and tabs should result in 12 spaces:'
printf "%q" "${RESULT}"
echo

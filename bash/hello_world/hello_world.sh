#!/bin/bash

echo "hello, world"

echo 'hello, world'

word="hello, world"
echo ${word}

word=hello\ '\t'\ world;
echo -e $word

echo -e "hello \t world"
echo -e 'hello \t world'

word="hello \t world"
echo -e $word

word='hello \t world'
echo -e $word

word=hello' ''\t 'world
echo -e $word

echo -e "\e[1;31mhello \t world \e[0m"
echo -e "\e[1;32mhello \t world \e[0m"
echo -e "\e[1;33mhello \t world \e[0m"
echo -e "\e[1;34mhello \t world \e[0m"
echo -e "\e[1;35mhello \t world \e[0m"
echo -e "\e[1;36mhello \t world \e[0m"
echo -e "\e[1;37mhello \t world \e[0m"


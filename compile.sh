#!/bin/bash

for i in $(ls *.cpp); do g++ -c $i; done;
g++ *.o -omain

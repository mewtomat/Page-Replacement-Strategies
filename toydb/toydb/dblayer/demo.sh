#! /bin/bash

OP=1
VAL=5

for ALGO in `seq 1 5`; do
        echo "-----------------------Algorithm $ALGO-------------------------------------" 
        echo `./a.out $ALGO 1 5`
    done
#!/bin/bash

rm -f results
./run100times.sh lru	>> results
./run100times.sh mru	>> results
./run100times.sh lfu	>> results
./run100times.sh fifo	>> results
./run100times.sh belady	>> results
./run100times.sh random	>> results

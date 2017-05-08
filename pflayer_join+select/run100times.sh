#! /bin/bash

for i in `seq 1 100`;
do
	# echo `./myselect.sh $1`
	echo `./myjoin.sh $1`
done

python calc_avg.py $1
rm $1_stats.txt
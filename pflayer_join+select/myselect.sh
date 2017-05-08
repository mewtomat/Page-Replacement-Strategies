python2.7 select_input_generator.py > select_input.txt
make clean &> /dev/null
# make select_mytestpf
./select_mytestpf $1 < select_input.txt >> $1_stats.txt

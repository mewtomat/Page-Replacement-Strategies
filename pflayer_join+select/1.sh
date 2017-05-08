echo "lru"
./select_mytestpf lru < $1 | tail -1
echo "mru"
./select_mytestpf mru < $1 | tail -1
echo "fifo"
./select_mytestpf fifo < $1 | tail -1
echo "lfu"
./select_mytestpf lfu < $1 | tail -1
echo "random"
./select_mytestpf random < $1 | tail -1
echo "belady"
./select_mytestpf belady < $1 | tail -1
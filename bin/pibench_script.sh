#! /bin/bash
echo "Measuring throughput"
echo "--------------------"
#echo "Size of hashtable = 5000"
#sudo ./PiBench ./Level.so -S 5000 -M THROUGHPUT
#sudo ./PiBench ./Level.so -S 10000 -M THROUGHPUT
#sudo ./PiBench ./Level.so -S 20000 -M THROUGHPUT
#sudo ./PiBench ./Level.so -S 40000 -M THROUGHPUT
#sudo ./PiBench ./Level.so -S 80000 -M THROUGHPUT
#sudo ./PiBench ./Level.so -S 160000 -M THROUGHPUT
#sudo ./PiBench ./Level.so -S 320000 -M THROUGHPUT

# throuput values
#hashtables=("CCEH" "PCLHT" "Level" "SOFT")

echo "Size,Throughput" >> "outputFile.txt"
#for i in ${!hashtables[@]};
#do
	for (( size=2048; size<=4194304; size*=2))
	do
		echo "Size of hashtable = $size"
		echo  ${hashtables[$i]}
		echo "$size" >> "outputFile.txt"
        sudo -E ./PiBench ./CCEH.so -S $size -M THROUGHPUT  
		# env LD_PRELOAD=/home/yjsoh/HashEvaluation/hash/Dash/pmdk/src/libpmemobj sudo -E ./PiBench ./CCEH.so -S $size -M THROUGHPUT  
		# export LD_PRELOAD=/home/yjsoh/HashEvaluation/hash/Dash/pmdk/src/libpmemobj; sudo -E ./PiBench ./PCLHT.so -S $size -M THROUGHPUT
		# sudo -E bash ./PiBench -c ./PCLHT.so -S $size -M THROUGHPUT 'echo $LD_PRELOAD=/home/yjsoh/HashEvaluation/hash/Dash/pmdk/src/libpmemobj'
		# env LD_PRELOAD=/home/yjsoh/HashEvaluation/hash/Dash/pmdk/src/libpmemobj 
	done
# done

## latency values 
#echo "Size,Percentile of num operations, Latency" >> "outputFileLatency.txt"
#for (( size = 2048; size<=4194304; size*=2))
#do
#	echo "$size" >> "outputFileLatency.txt"
#        sudo ./PiBench ./clevel.so -S $size -M LATENCY
#        echo "\n"
#done
# the percentile of number operations
# generating plots and seeing if there's any kind of diff between hashtables

# 1) 4GB
# 2) create array with all the .so files and go through all of them with loop

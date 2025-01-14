NUM_CORES=8
RES_FOLDER=$(pwd)/res_SLP

mkdir -p $RES_FOLDER

	
	../../run-sniper -v -n $NUM_CORES -c gainestown -g perf_model/branch_predictor/inputs=64 -g perf_model/branch_predictor/threshold=7 -g perf_model/branch_predictor/weight=30   -d $RES_FOLDER/run_1 --power -- ./fft -p $NUM_CORES > $RES_FOLDER/console_output1.txt 2>&1
	
	../../run-sniper -v -n $NUM_CORES -c gainestown -g perf_model/branch_predictor/inputs=64 -g perf_model/branch_predictor/threshold=7 -g perf_model/branch_predictor/weight=30   -d $RES_FOLDER/run_2 --power -- ./fft -p $NUM_CORES > $RES_FOLDER/console_output2.txt 2>&1
	
	../../run-sniper -v -n $NUM_CORES -c gainestown -g perf_model/branch_predictor/inputs=64 -g perf_model/branch_predictor/threshold=7 -g perf_model/branch_predictor/weight=30   -d $RES_FOLDER/run_3 --power -- ./fft -p $NUM_CORES > $RES_FOLDER/console_output3.txt 2>&1
	
	../../run-sniper -v -n $NUM_CORES -c gainestown -g perf_model/branch_predictor/inputs=64 -g perf_model/branch_predictor/threshold=7 -g perf_model/branch_predictor/weight=30   -d $RES_FOLDER/run_4 --power -- ./fft -p $NUM_CORES > $RES_FOLDER/console_output4.txt 2>&1
	
	../../run-sniper -v -n $NUM_CORES -c gainestown -g perf_model/branch_predictor/inputs=64 -g perf_model/branch_predictor/threshold=7 -g perf_model/branch_predictor/weight=30   -d $RES_FOLDER/run_5 --power -- ./fft -p $NUM_CORES > $RES_FOLDER/console_output5.txt 2>&1
	
	../../run-sniper -v -n $NUM_CORES -c gainestown -g perf_model/branch_predictor/inputs=64 -g perf_model/branch_predictor/threshold=7 -g perf_model/branch_predictor/weight=30   -d $RES_FOLDER/run_6 --power -- ./fft -p $NUM_CORES > $RES_FOLDER/console_output6.txt 2>&1
	
	../../run-sniper -v -n $NUM_CORES -c gainestown -g perf_model/branch_predictor/inputs=64 -g perf_model/branch_predictor/threshold=7 -g perf_model/branch_predictor/weight=30   -d $RES_FOLDER/run_7 --power -- ./fft -p $NUM_CORES > $RES_FOLDER/console_output7.txt 2>&1
	
	../../run-sniper -v -n $NUM_CORES -c gainestown -g perf_model/branch_predictor/inputs=64 -g perf_model/branch_predictor/threshold=7 -g perf_model/branch_predictor/weight=30   -d $RES_FOLDER/run_8 --power -- ./fft -p $NUM_CORES > $RES_FOLDER/console_output8.txt 2>&1	

	../../run-sniper -v -n $NUM_CORES -c gainestown -g perf_model/branch_predictor/inputs=64 -g perf_model/branch_predictor/threshold=7 -g perf_model/branch_predictor/weight=30   -d $RES_FOLDER/run_9 --power -- ./fft -p $NUM_CORES > $RES_FOLDER/console_output9.txt 2>&1
	
	../../run-sniper -v -n $NUM_CORES -c gainestown -g perf_model/branch_predictor/inputs=64 -g perf_model/branch_predictor/threshold=7 -g perf_model/branch_predictor/weight=30   -d $RES_FOLDER/run_10 --power -- ./fft -p $NUM_CORES > $RES_FOLDER/console_output10.txt 2>&1	
	


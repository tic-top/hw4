main: main.cu
	nvcc -o out main.cu -std=c++11 -O3
	nvcc -o out_500 main_500.cu -std=c++11 -O3
	nvcc -o out_1000 main_1000.cu -std=c++11 -O3
	nvcc -o out_2000 main_2000.cu -std=c++11 -O3

clean:
	rm out* time* sl* out* s*
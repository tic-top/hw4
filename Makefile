main: main.cu
	nvcc -o out main.cu -std=c++11 -O3

clean:
	rm out* time* sl* out* s*
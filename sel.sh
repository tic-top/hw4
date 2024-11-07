#!/bin/bash
# (See https://arc-ts.umich.edu/greatlakes/user-guide/ for command details)
# Set up batch job settings

#SBATCH --job-name=submit
#SBATCH --mail-type=END
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --mem-per-cpu=1g
#SBATCH --time=00:05:00
#SBATCH --account=cse587f24_class
#SBATCH --partition=standard

g++ -std=c++11 -O3 -fopenmp -o s main.cpp
./s 500 10 > sel_500.txt
./s 1000 10 > sel_1000.txt
./s 2000 10 > sel_2000.txt
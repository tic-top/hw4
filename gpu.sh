#!/bin/bash
# (See https://arc-ts.umich.edu/greatlakes/user-guide/ for command details)
# Set up batch job settings

#SBATCH --job-name=submit
#SBATCH --mail-type=END
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --gres=gpu:1
#SBATCH --mem-per-cpu=1g
#SBATCH --time=00:05:00
#SBATCH --account=cse587f24_class
#SBATCH --partition=gpu

make
# { time ./out 10 > out.txt ; } 2> time.txt
./out_500 10 > out_500.txt
./out_1000 10 > out_1000.txt
./out_2000 10 > out_2000.txt


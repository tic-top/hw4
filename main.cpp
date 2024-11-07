//
// n=500, 1000, 2000
// t=10
// double precision
// less than 5 min
//

#include <iostream>
#include <chrono>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <cmath>
#include <vector>
using namespace std;
using namespace std::chrono;
int main(int argc, char *argv[])
{
    long n = atoi(argv[1]);
    int t = atoi(argv[2]);

    // create A and B with size n x n
    // remember n is a variable, 2d vector maybe a good choice
    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> B(n, vector<double>(n));

    auto start = high_resolution_clock::now();

    for (double i = 0; i < n; ++i)
    {
        for (double j = 0; j < n; ++j)
        {
            A[(long) i][(long) j] = (1 + cos(2 * i) + sin(j)) * (1 + cos(2 * i) + sin(j));
        }
    }
    // printA
    // for (int i = 0; i < 5; ++i)
    // {
    //     for (int j = 0; j < 5; ++j)
    //     {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    double tmp0, tmp1;
    for (int tao = 0; tao < t; ++tao)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                B[i][j] = A[i][j];
                if (!(i == 0 || i == n - 1 || j == 0 || j == n - 1))
                {
                    // method1
                    // tmp0 = A[i-1][j-1] < A[i+1][j+1] ? A[i-1][j-1] : A[i+1][j+1];
                    // tmp1 = A[i-1][j-1] + A[i+1][j+1] - tmp0;

                    // if (A[i+1][j-1] <= tmp0) {
                    //     tmp1 = tmp0;
                    //     tmp0 = A[i+1][j-1];
                    // } else if (A[i+1][j-1] <= tmp1) {
                    //     tmp1 = A[i+1][j-1];
                    // }

                    // if (A[i-1][j+1] <= tmp0) {
                    //     tmp1 = tmp0;
                    //     tmp0 = A[i-1][j+1];
                    // } else if (A[i-1][j+1] <= tmp1) {
                    //     tmp1 = A[i-1][j+1];
                    // }

                    // method2
                    tmp0 = min(max(A[i - 1][j - 1], A[i + 1][j + 1]), max(A[i + 1][j - 1], A[i - 1][j + 1]));
                    tmp1 = max(min(A[i - 1][j - 1], A[i + 1][j + 1]), min(A[i + 1][j - 1], A[i - 1][j + 1]));
                    tmp1 = min(tmp1, tmp0);

                    B[i][j] += tmp1;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                A[i][j] = B[i][j];
            }
        }
    }

    double s = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            s += A[i][j];
        }
    }
    cout << "sum = " << s << "\n";
    cout << "A[37, 47] = " << A[37][47] << "\n";

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time: " << duration.count() << " ms" << "\n";
    return 0;
}

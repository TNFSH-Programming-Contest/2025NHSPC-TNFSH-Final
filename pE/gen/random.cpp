#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]),  m = atoi(argv[2]);
    int N = rnd.next(1, n);
    int K = rnd.next(1, N);
    int M = rnd.next(1, m);
    println(N, K, M);
}

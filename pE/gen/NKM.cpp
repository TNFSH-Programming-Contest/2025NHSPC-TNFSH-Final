#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]), K = atoi(argv[2]), M = atoi(argv[3]), w = atoi(argv[4]);
    vector< int > a(K);
    for(int i = 0; i < K; ++i){
        a[i] = rnd.wnext(1, N, w);
    }
    println(N, K, M);
    println(a);
}

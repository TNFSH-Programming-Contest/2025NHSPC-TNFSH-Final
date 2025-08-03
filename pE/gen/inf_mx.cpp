#include <iostream>
#include <array>
#include "testlib.h"
using namespace std;
const int maxc = 1e9;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]);
	int Q = atoi(argv[2]);
    vector< array<int, 3> > ask;

	vector< int > C(N);
	for(int i = 0; i < N; ++i){
		C[i] = (i & 1);
	}
    int i = 0;
    for(int i = 0; i < Q / 2 - 50; ++i){
        ask.push_back({1, 1, N});
    }
	for(i = 0; i < 40; ++i){
        ask.push_back({2, 1, N});
	}
    int x = rnd.next(0, N / 2 - 1);
    x = x * 2 + 1;
    for(; i < Q / 2; ++i){
        ask.push_back({4, x, (int)1e9});
    }
    println(N, Q);
    println(C);
    for(auto &[a, b, c] : ask){
        println(a, b, c);
    }
}

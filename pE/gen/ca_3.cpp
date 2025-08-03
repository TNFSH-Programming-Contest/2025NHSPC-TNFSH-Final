#include <iostream>
#include <array>
#include "testlib.h"
using namespace std;
const int maxc = 1e9;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]);
	int Q = atoi(argv[2]);
	int S = atoi(argv[3]);
    int W = atoi(argv[3]);
    vector< array<int, 3> > ask;

	vector< int > C(N);
	for(int i = 0; i < N; ++i){
		C[i] = (i & 1);
	}
    for(int i = 0; i < Q - 10; ++i){
        int l = rnd.wnext(1, N, W);
        int r = rnd.wnext(l, N, W);
		ask.push_back({1, l, r});
	}
    int x = 1;
    if(S == 3) x = maxc;
    ask.push_back({4, 1, x});
    ask.push_back({4, 1, x});
    ask.push_back({3, 1, N});
    ask.push_back({4, 1, x});
    ask.push_back({4, 3, x});
    println(N, (int)ask.size());
    println(C);
    for(auto &[a, b, c] : ask){
        println(a, b, c);
    }
}

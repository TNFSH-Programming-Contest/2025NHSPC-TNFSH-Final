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
	int x = rnd.next(0, N / 2 - 1) * 2 + 1;
	int val = 1;
    for(int i = 0; i < Q / 40; ++i){
		for(int j = 0; j < 29; ++j){
			ask.push_back({2, 1, N});
			val *= 2;
		}
		ask.push_back({4, x, val - 1});
		val = 1;
	}
    println(N, (int)ask.size());
    println(C);
    for(auto &[a, b, c] : ask){
        println(a, b, c);
    }
}

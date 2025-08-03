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
	int W = atoi(argv[4]);
	vector< int > C(N);
	for(int i = 0; i < N; ++i){
		C[i] = rnd.next(0, maxc);
	}
	println(N, Q);
	println(C);
	for(int i = 0; i < Q; ++i){
		int t = rnd.next(1, 3);
		if(t == 3) ++t;
		if(t == 4){
			int x = rnd.next(1, N);
			int k = rnd.next(1, maxc);
			if(S == 3) k = 1e9;
			println(t, x, k);
		}
		else{
			int l = rnd.wnext(1, N, -W);
			int r = rnd.wnext(l, N, W);
			if(t == 1 && S == 2){
				l = r;
			}
			println(t, l, r);
		}
	}
}

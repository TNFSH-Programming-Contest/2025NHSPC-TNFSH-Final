#include "testlib.h"
#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main(int argc, char* argv[]) {
	registerChecker("clock", argc, argv);
	int N = inf.readInt(1, 200000);
	int M = inf.readInt(1, 1000000000);
	vector< array<int, 2> > v(N);
	for(int i = 0; i < N; ++i){
		v[i][0] = inf.readInt(0, M - 1);
		v[i][1] = inf.readInt(0, M - 1);
	}
	int T = ouf.readInt(0, N);
	vector< int > vis(N + 1);
	for(int t = 1; t <= T; ++t){
		int n = ouf.readInt(1, N);
		int k = ouf.readInt(0, M - 1);
		for(int i = 0; i < n; ++i){
			int x = ouf.readInt(1, N);
			if(vis[x]) quit(_wa);
			vis[x] = 1;
			v[x - 1][0] = (v[x - 1][0] + k) % M;
		}
	}
	int ok = 1;
	for(int i = 0; i < N; ++i){
		if(v[i][0] < v[i][1]) ok = 0;
	}
	if(!ok) quit(_wa);
	int best = ans.readInt(0, N);
	if(T <= best) quit(_ok);
	else quitp(0.3);
}

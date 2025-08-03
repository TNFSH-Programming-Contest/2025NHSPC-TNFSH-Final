#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]);
	int Q = atoi(argv[2]);
	int C = atoi(argv[3]);
	int W1 = atoi(argv[4]);
	vector< int > c(N + 1), par(N + 1);

	cout << N << " " << Q << "\n";
	for(int i = 1; i <= N; ++i){
		c[i] = rnd.next(1, C);
		cout << c[i] << " \n"[i == N];
	}
	for(int i = 2; i <= N; ++i){
		par[i] = rnd.wnext(1, i - 1, W1 * i);
		cout << i << " " << par[i] << "\n";
	}
	for(int i = 1; i <= Q; ++i){
		int a = rnd.next(1, N), b = rnd.next(1, N);
		int t = rnd.next(1, C);
		cout << a << " " << b << " " << t << "\n";
	}
}

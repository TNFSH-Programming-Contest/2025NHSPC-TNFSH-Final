#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]);
	int Q = atoi(argv[2]);
	int W1 = atoi(argv[3]);
    int W2 = atoi(argv[4]);
    int W3 = atoi(argv[5]);

	vector< int > c(N + 1), par(N + 1);

	cout << N << " " << Q << "\n";
	for(int i = 1; i <= N; ++i){
		c[i] = rnd.wnext(1, i, i);
		cout << c[i] << " \n"[i == N];
	}
	for(int i = 2; i <= N; ++i){
		par[i] = rnd.wnext(1, i - 1, W1 * i);
		cout << i << " " << par[i] << "\n";
	}
	for(int i = 1; i <= Q; ++i){
		int a = rnd.wnext(1, N, -W2), b = rnd.wnext(1, N, W2);
		int t = rnd.wnext(a, b, W3);
		cout << a << " " << b << " " << t << "\n";
	}
}

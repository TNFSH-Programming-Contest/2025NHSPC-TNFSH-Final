#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]);
	int Q = atoi(argv[2]);
	int C = atoi(argv[3]);
	int W1 = atoi(argv[4]);
    int W2 = 100;

	vector< int > c(N + 1);
	cout << N << " " << Q << "\n";
	for(int i = 1; i <= N; ++i){
		c[i] = rnd.next(1, C);
		cout << c[i] << " \n"[i == N];
	}
	for(int i = 1; i < N; ++i){
		cout << i << " " << i + 1 << "\n";
	}
	for(int i = 1; i <= Q; ++i){
		int a = rnd.wnext(1, N, -W2), b = rnd.wnext(1, N, W2);
		int t = rnd.next(1, C);
		cout << a << " " << b << " " << t << "\n";
	}
}

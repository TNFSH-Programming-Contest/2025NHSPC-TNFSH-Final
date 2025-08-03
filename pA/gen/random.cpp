#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]), K = atoi(argv[2]), C = atoi(argv[3]), W = atoi(argv[4]);
	K = (N - 1) - K;
	cout << N << " " << K << "\n";
	for(int i = 0; i < N; ++i){
		int x = rnd.wnext(1, C, W);
		cout << x << " \n"[i == N - 1];
	}
}

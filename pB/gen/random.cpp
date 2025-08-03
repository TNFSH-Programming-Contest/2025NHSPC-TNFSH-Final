#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]), K = atoi(argv[2]), L = atoi(argv[3]), R = atoi(argv[4]), W = atoi(argv[5]);
	cout << N << " " << K << "\n";
    for(int i = 0; i < N; ++i){
        int x = rnd.wnext(L, R, W);
        cout << x << " \n"[i == N - 1];
    }
}

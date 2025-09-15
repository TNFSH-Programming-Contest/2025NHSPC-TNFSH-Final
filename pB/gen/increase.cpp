#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]), K = atoi(argv[2]), F = atoi(argv[3]), D = atoi(argv[4]);
	cout << N << " " << K << "\n";
    for(int i = 0; i < N; ++i){
        cout << F << " \n"[i == N - 1];
        F += D;
    }
}

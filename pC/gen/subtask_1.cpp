#include <iostream>

#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]), m = atoi(argv[2]);
	cout << n << " " << m << "\n";
    int l = rnd.next(0, m - 1);
	for(int i = 0; i < n; ++i){
		int r = rnd.next(0, m - 1);
		cout << l << " " << r << "\n";
	}
}

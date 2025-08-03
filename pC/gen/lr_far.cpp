#include <iostream>

#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]), m = atoi(argv[2]), w = atoi(argv[3]);
	cout << n << " " << m << "\n";
	for(int i = 0; i < n; ++i){
		int l = rnd.wnext(0, m - 1, -w), r = rnd.wnext(l, m - 1, w);
		cout << l << " " << r << "\n";
	}
}

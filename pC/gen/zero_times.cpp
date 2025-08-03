#include <iostream>

#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]), m = atoi(argv[2]);
	cout << n << " " << m << "\n";
	for(int i = 0; i < n; ++i){
		int l = rnd.next(0, m - 1), r = rnd.next(0, m - 1);
		if(l < r) swap(l, r);
		cout << l << " " << r << "\n";
	}
}

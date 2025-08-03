#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "testlib.h"
using namespace std;

int key = 20807;
int code(int x){
    return (x ^ key);
}
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	vector< int > v(n);
	iota(v.begin(), v.end(), 1);
    reverse(v.begin(), v.end());
	println(n, n);
	for(int i = 0; i < n; ++i) cout << code(v[i]) << " \n"[i == n - 1];
	for(int i = 1; i <= n; ++i) cout << i << " \n"[i == n];
}

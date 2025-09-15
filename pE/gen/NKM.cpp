#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]), k = atoi(argv[2]), m = atoi(argv[3]);
    println(n, k, m);
}

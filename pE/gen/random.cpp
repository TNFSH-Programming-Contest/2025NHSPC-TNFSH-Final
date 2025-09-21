#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]), m = atoi(argv[2]), w = atoi(argv[3]), s = atoi(argv[4]);
    int N = rnd.wnext(1, n, w);
    int now = rnd.next(1, N);
    int M = rnd.next(1, m);
    if(s == 2) M = 998244353;
    vector< int > a;
    if(s == 3){
        a.push_back(now);
    }
    else if(s == 1){
        for(int i = 0; i < N; ++i) a.push_back(1);
    }
    else{
        while(now){
            int t = rnd.next(1, now);
            a.push_back(t);
            now -= t;
        }
    }
    int K = a.size();
    println(N, K, M);
    println(a);
}

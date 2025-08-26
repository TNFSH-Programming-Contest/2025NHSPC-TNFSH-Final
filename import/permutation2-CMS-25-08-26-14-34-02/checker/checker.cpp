#include "testlib.h"
using namespace std;

const string output_secret = "BwX79QYzyAbxnmpqVLfwPV2Niz9fYyb5";
int key = 20807;
int code(int x){
    return (x ^ key);
}

int main(int argc, char* argv[]) {
	registerChecker("permutation2", argc, argv);
	readBothSecrets(output_secret);
	int n = inf.readInt(1, 1000);
	int k = inf.readInt(1, 1000);
	vector< int > v(n + 1);
	for(int i = 1; i <= n; ++i){
		v[i] = inf.readInt();
		v[i] = code(v[i]);
	}
	for(int i = 1; i <= k; ++i){
		int a = inf.readInt(1, n);
		int b = ouf.readInt(1, n);
		if(v[a] != b) quit(_wa);
	}
	int Q = ouf.readInt();
	if(Q == 0) quit(_ok);
	else if(Q <= 1000){
		quitp(1.0 - sqrt(Q) / 50);
	}
	else quit(_wa);
}

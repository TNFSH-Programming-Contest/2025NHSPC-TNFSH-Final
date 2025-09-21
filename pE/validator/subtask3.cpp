#include "testlib.h"
using namespace std;

const int maxn = 200000;
const int maxc = 1e9 + 7;
int main() {
	registerValidation();
	int N = inf.readInt(1, maxn);
	inf.readSpace();
    int K = inf.readInt(1, 1);
	inf.readSpace();
	int M = inf.readInt(2, maxc);
	inf.readEoln();
	for(int i = 0; i < K; ++i){
		inf.readInt(1, N);
		if(i == K - 1) inf.readEoln();
		else inf.readSpace();
	}
	inf.readEof();
}

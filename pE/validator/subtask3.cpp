#include "testlib.h"
using namespace std;

const int maxn = 40;
const int maxc = 1e9 + 7;
int main() {
	registerValidation();
	int N = inf.readInt(1, maxn);
	inf.readSpace();
    int K = inf.readInt(1, N);
	inf.readSpace();
	int M = inf.readInt(2, maxc);
	inf.readEoln();
	inf.readEof();
	for(int i = 2; i * i <= M; ++i){
		ensure(M % i != 0);
	}
}

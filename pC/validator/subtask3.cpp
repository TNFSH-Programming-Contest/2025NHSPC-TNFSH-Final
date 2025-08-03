#include "testlib.h"
using namespace std;

const int maxn = 2e5;
const int maxc = 1e9;
int main() {
	registerValidation();
	int N = inf.readInt(1, maxn);
    inf.readSpace();
    int M = inf.readInt(1, maxc);
    inf.readEoln();
    vector< int > A(N + 1), B(N + 1);
	for(int i = 1; i <= N; ++i){
        A[i] = inf.readInt(0, M - 1);
        inf.readSpace();
        B[i] = inf.readInt(0, M - 1);
        inf.readEoln();
        ensure(B[i] == B[1]);
    }
    inf.readEof();
}

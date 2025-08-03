#include "testlib.h"
using namespace std;

const int maxn = 1e5;
int main() {
	registerValidation();
	int N = inf.readInt(2, maxn);
    inf.readSpace();
    int K = inf.readInt(0, N - 1);
    ensure(K == N - 1);
    inf.readEoln();
    for(int i = 1; i <= N; ++i){
        inf.readInt(1, N);
        if(i == N) inf.readEoln();
        else inf.readSpace();
    }
    inf.readEof();
}

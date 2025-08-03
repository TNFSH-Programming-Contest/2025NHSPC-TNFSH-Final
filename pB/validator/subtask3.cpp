#include "testlib.h"
using namespace std;

const int maxn = 5e5;
const int maxc = 1;
int main() {
	registerValidation();
	int N = inf.readInt(1, maxn);
    inf.readSpace();
    int K = inf.readInt(1, N);
    inf.readEoln();
	for(int i = 1; i <= N; ++i){
        inf.readInt(-maxc, maxc);
        if(i == N) inf.readEoln();
        else inf.readSpace();
    }
    inf.readEof();
}

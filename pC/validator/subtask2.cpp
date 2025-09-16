#include "testlib.h"
using namespace std;

const int maxn = 2000;
const int maxc = 1e9;
int main() {
	registerValidation();
	int N = inf.readInt(1, maxn);
    inf.readSpace();
    int M = inf.readInt(1, maxc);
    inf.readEoln();
	for(int i = 1; i <= N; ++i){
        inf.readInt(0, M - 1);
        inf.readSpace();
        inf.readInt(0, M - 1);
        inf.readEoln();
    }
    inf.readEof();
}

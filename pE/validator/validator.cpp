#include "testlib.h"
using namespace std;

const int maxn = 1e5;
const int maxc = 1e9;
int main() {
	registerValidation();
	int N = inf.readInt(1, maxn);
    inf.readSpace();
    int Q = inf.readInt(1, maxn);
    inf.readEoln();
	for(int i = 1; i <= N; ++i){
        inf.readInt(0, maxc);
		if(i == N) inf.readEoln();
		else inf.readSpace();
    }
	for(int i = 0; i < Q; ++i){
		int t = inf.readInt(1, 4);
		inf.readSpace();
		if(t == 4){
			int x = inf.readInt(1, N);
			inf.readSpace();
			int k = inf.readInt(1, maxc);
		}
		else{
			int l = inf.readInt(1, N);
			inf.readSpace();
			int r = inf.readInt(l, N);
		}
		inf.readEoln();
	}
    inf.readEof();
}

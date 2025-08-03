#include "testlib.h"
using namespace std;

const int maxn = 1000;
int key = 20807;
int code(int x){
    return (x ^ key);
}
int main() {
	registerValidation();
	int N = inf.readInt(3, maxn);
    inf.readSpace();
    int K = inf.readInt(1, maxn);
    inf.readEoln();
    vector< int > vis(N + 1);
    for(int i = 1; i <= N; ++i){
        int c = inf.readInt();
        c = code(c);
        ensure(1 <= c && c <= N);
        ensure(!vis[c]++);
        if(i == N) inf.readEoln();
        else inf.readSpace();
    }
    for(int i = 1; i <= K; ++i){
        inf.readInt(1, N);
        if(i == K) inf.readEoln();
        else inf.readSpace();
    }
    inf.readEof();
}

#include "testlib.h"
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
#define all(v) v.begin(), v.end()

const int maxn = 1e5;
struct DSU{
	vector< int > dsu, sz;
	DSU(int n){ dsu.resize(n + 1); sz.resize(n + 1, 1); iota(all(dsu), 0); }
	int find(int a){ return dsu[a] == a ? a : dsu[a] = find(dsu[a]); }
	void merge(int a, int b){
		a = find(a); b = find(b);
        if(a == b) return;
		if(sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a], dsu[a] = b;
	}
	bool same(int a, int b){ return find(a) == find(b); }
};
int main() {
	registerValidation();
	int N = inf.readInt(1, maxn);
    inf.readSpace();
    int Q = inf.readInt(1, maxn);
    inf.readEoln();
    for(int i = 1; i <= N; ++i){
        inf.readInt(1, 2);
        if(i == N) inf.readEoln();
        else inf.readSpace();
    }
    DSU dsu(N);
    for(int i = 1; i < N; ++i){
        int u = inf.readInt(1, N);
        inf.readSpace();
        int v = inf.readInt(1, N);
        inf.readEoln();
        ensure(!dsu.same(u, v));
        dsu.merge(u, v);
    }
    for(int i = 1; i <= Q; ++i){
        inf.readInt(1, N);
        inf.readSpace();
        inf.readInt(1, N);
        inf.readSpace();
        inf.readInt(1, N);
        inf.readEoln();
    }
    inf.readEof();
}

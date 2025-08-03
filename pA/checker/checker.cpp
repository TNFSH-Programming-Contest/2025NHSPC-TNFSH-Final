#include "testlib.h"
#include <vector>
#include <algorithm>
#include <numeric>
#define all(v) v.begin(), v.end()
using namespace std;
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
int main(int argc, char* argv[]) {
	registerChecker("tribe", argc, argv);
	string s = ouf.readToken();
	string t = ans.readToken();
	if(s != t) quit(_wa);
	if(s == "No") quit(_ok);
	int n = inf.readInt();
	int k = inf.readInt();
	k = (n - 1) - k;
	vector< int > c(n + 1);
	DSU dsu(n);
	for(int i = 1; i <= n; ++i) c[i] = inf.readInt();
	int cnt = 0;
	for(int i = 1; i < n; ++i){
		int a = ouf.readInt(1, n);
		int b = ouf.readInt(1, n);
		if(c[a] != c[b]) ++cnt;
		if(dsu.same(a, b)) quit(_wa);
		dsu.merge(a, b);
	}
	if(cnt != k) quit(_wa);
	else quit(_ok);
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<utility>
#include<cassert>

#define pii pair<int, int>
using namespace std;

struct BIT{
	int n;
	vector< int > tree;
	BIT(int N){
		n = N;
		tree.resize(n + 1);
	}
	void modify(int id, int val){
		for(; id <= n; id += id&-id) tree[id] += val;
	}
	int query(int id){
		int ret = 0;
		for(; id; id -= id &-id) ret += tree[id];
		return ret;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector< vector< int > > c(n + 1);
	vector< int > C(n + 1);
	for(int i = 0; i < n; ++i){
		cin >> C[i];
		c[C[i]].push_back(i);
	}
	vector< vector< int > > g(n);
	for(int i = 1; i < n; ++i){
		int a, b; cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector< vector< array<int, 3> > > ask(n + 1);
	for(int i = 0; i < q; ++i){
		int a, b, t;
		cin >> a >> b >> t;
		--a, --b;
		ask[t].push_back({a, b, i});
	}
	vector< int > in(n), out(n), dep(n);
	vector< vector< int > > anc(20, vector< int >(n));
	int tag = 1;
	auto dfs = [&](auto dfs, int cur, int par) -> void {
		dep[cur] = dep[par] + 1;
		anc[0][cur] = par;
		for(int i = 1; i < 20; ++i) anc[i][cur] = anc[i - 1][anc[i - 1][cur]];
		in[cur] = tag++;
		for(auto &k : g[cur]) if(k != par){
			dfs(dfs, k, cur);
		}
		out[cur] = tag;
	};
	dfs(dfs, 0, 0);
	auto lca = [&](int a, int b) -> int {
		if(dep[a] < dep[b]) swap(a, b);
		for(int d = dep[a] - dep[b], p = 0; d; d >>= 1, ++p) if(d & 1){
			a = anc[p][a];
		}
		if(a == b) return a;
		for(int i = 19; i >= 0; --i){
			if(anc[i][a] != anc[i][b]){
				a = anc[i][a];
				b = anc[i][b];
			}
		}
		assert(anc[0][a] == anc[0][b]);
		return anc[0][a];
	};
	BIT bit(tag + 1);
	vector< int > ans(q);
	for(int col = 1; col <= n; ++col){
		for(auto &x : c[col]){
			bit.modify(in[x], 1);
			bit.modify(out[x], -1);
		}
		for(auto &[a, b, id] : ask[col]){
			if(C[a] == col){
				ans[id] = a;
				continue;
			}
			int l = lca(a, b);
			if(bit.query(in[a]) > bit.query(in[l])){
				int t = a;
				for(int i = 19; i >= 0; --i){
					if(bit.query(in[anc[i][t]]) == bit.query(in[t])){
						t = anc[i][t];
					}
				}
				ans[id] = t;
				continue;
			}
			if(C[l] == col){
				ans[id] = l;
				continue;
			}
			if(bit.query(in[b]) > bit.query(in[l])) {
				int t = b;
				int mn = bit.query(in[l]);
				for(int i = 19; i >= 0; --i){
					if(dep[anc[i][t]] > dep[l] && bit.query(in[anc[i][t]]) > mn){
						t = anc[i][t];
					}
				}
				ans[id] = t;
			}
			else ans[id] = -2;
		}
		for(auto &x : c[col]){
			bit.modify(in[x], -1);
			bit.modify(out[x], 1);
		}
	}
	for(int i = 0; i < q; ++i) cout << ans[i] + 1 << "\n";
}

/*
10 1
1 6 5 3 6 7 2 10 8 1
2 1
3 1
4 2
5 2
6 4
7 1
8 3
9 2
10 5
9 2 1
*/
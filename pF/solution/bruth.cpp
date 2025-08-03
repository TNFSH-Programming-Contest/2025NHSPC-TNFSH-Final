#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<utility>
#include<cassert>

#define pii pair<int, int>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector< vector< int > > c(n + 1);
	vector< int > C(n + 1);
	for(int i = 0; i < n; ++i){
		cin >> C[i];
	}
	vector< vector< int > > g(n);
	for(int i = 1; i < n; ++i){
		int a, b; cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector< int > dep(n), fa(n);
	auto dfs = [&](auto dfs, int cur, int par) -> void {
		dep[cur] = dep[par] + 1;
		fa[cur] = par;
		for(auto &k : g[cur]) if(k != par){
			dfs(dfs, k, cur);
		}
	};
	dfs(dfs, 0, 0);
    while(q--){
        int a, b, col;
        cin >> a >> b >> col;
        --a, --b;
        int ans = -2;
        if(C[a] == col){
            cout << a + 1 << "\n";
            continue;
        }
        if(C[b] == col) ans = b;

        while(a != b){
            if(dep[a] > dep[b]){
                a = fa[a];
            }
            else if(dep[b] > dep[a]){
                b = fa[b];
            }else{
                a = fa[a];
                b = fa[b];
            }
            if(C[a] == col){
                ans = a;
                break;
            }
            if(C[b] == col) ans = b;
        }
        cout << ans + 1 << "\n";
    }
}

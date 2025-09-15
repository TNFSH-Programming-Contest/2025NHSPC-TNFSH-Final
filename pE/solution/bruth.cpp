#include<bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;//    998244353;
const int llmx = 1e18;

void sol(){
    int n, k, m;
    cin >> n >> k >> m;
    vector< int > usedr(n), usedc(n);
    int ans = 0;
    auto dfs = [&](auto dfs, int id, int fi) -> void {
        if(id == k){
            ++ans;
            return;
        }
        for(int i = fi; i < n; ++i) if(!usedr[i]){
            for(int j = 0; j < n; ++j) if(!usedc[j]){
                usedr[i] = 1, usedc[j] = 1;
                dfs(dfs, id + 1, i);
                usedr[i] = 0, usedc[j] = 0;
            }
        }
    };
    dfs(dfs, 0, 0);
    cout << ans % m << "\n";
}
/*


*/
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
    int t = 1; //cin >> t;
    while(t--) sol();
}
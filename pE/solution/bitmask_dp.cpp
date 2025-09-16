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
    vector< int > dp(1 << n);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        for(int mask = (1 << n) - 1; mask >= 0; --mask){
            for(int j = 0; j < n; ++j) if(!(mask >> j & 1)){
                int nxt = mask | (1 << j);
                dp[nxt] += dp[mask];
                if(dp[nxt] >= m) dp[nxt] -= m;
            }
        }
    }
    int ans = 0;
    for(int mask = 0; mask < (1 << n); ++mask) if(__builtin_popcountll(mask) == k){
        ans += dp[mask];
        if(ans >= m) ans -= m;
    }
    cout << ans << "\n";
}
/*


*/
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
    int t = 1; //cin >> t;
    while(t--) sol();
}
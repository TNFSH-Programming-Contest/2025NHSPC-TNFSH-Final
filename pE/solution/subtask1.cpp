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
    int sum = 0;
    vector< int > a(k);
    for(auto &i : a) cin >> i, sum += i;
    if(sum > n) cout << "0\n";
    else{
        assert(sum == n);
        int ans = 1;
        for(int i = 1; i <= n; ++i) ans = ans * i % m;
        ans = ans * ans % m;
        cout << ans << "\n";
    }
}
/*


*/
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
    int t = 1; //cin >> t;
    while(t--) sol();
}
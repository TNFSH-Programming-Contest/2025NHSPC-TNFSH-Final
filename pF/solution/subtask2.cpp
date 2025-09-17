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
    int n, q;
    cin >> n >> q;
    vector< vector< int > > c(n + 1);
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        c[x].push_back(i);
    }
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
    }
    while(q--){
        int a, b, t;
        cin >> a >> b >> t;
        if(a < b){
            auto it = lower_bound(all(c[t]), a);
            if(it == c[t].end() || *it > b) cout << "-1\n";
            else cout << *it << "\n";
        }
        else{
            auto it = upper_bound(all(c[t]), a);
            if(it == c[t].begin() || *prev(it) < b) cout << "-1\n";
            else cout << *prev(it) << "\n";
        }
    }
}
/*


*/
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
    int t = 1; //cin >> t;
    while(t--) sol();
}
#include<bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;
const int maxn = 2e5 + 10;
 int mod = 1e9 + 7;//    998244353;
const int llmx = 1e18;

int fpow(int a, int b = mod - 2){
    int re = 1;
    while(b){
        if(b & 1) re = re * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return re;
}
void sol(){
    int n, k;
    cin >> n >> k >> mod;
    vector< int > fac(n + 1), ifac(n + 1);
    fac[0] = 1;
    for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
    ifac[n] = fpow(fac[n]);
    for(int i = n - 1; i >= 0; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
    auto C = [&](int n, int m) -> int {
        if(m > n) return 0;
        return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
    };
    vector< int > a(k);
    int s = 0;
    for(auto &i : a) cin >> i, s += i;
    int ans = C(n, s) * C(n, s) % mod * fac[s] % mod * fac[s] % mod;
    for(auto &i : a) ans = ans * ifac[i] % mod;
    cout << ans << "\n";
}
/*


*/
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
    int t = 1; //cin >> t;
    while(t--) sol();
}
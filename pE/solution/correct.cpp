#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, k, mod;
    cin >> n >> k >> mod;
    int sum = 0;
    vector< int > a(k);
    for(int i = 0; i < k; ++i) cin >> a[i], sum += a[i];
    if(sum > n){
        cout << "0\n";
        return 0;
    }
    int ans = 1;
    vector< int > mul(n + 1);
    auto add = [&](int x, int val) -> void {
        for(int i = 1; i <= x; ++i) mul[i] += val;
    };
    add(n, 2);
    add(sum, -1);
    add(n - sum, -2);
    add(sum, 1);
    for(auto i : a) add(i, -1);
    for(int t = n; t > 1; --t){
        vector< pair<int, int> > tmp;
        int now = t;
        for(int i = 2; i * i <= now; ++i){
            if(now % i == 0){
                int cnt = 0;
                while(now % i == 0) ++cnt, now /= i;
                tmp.push_back({i, cnt});
            }
        }
        if(tmp.empty()){
            for(int i = 0; i < mul[t]; ++i) ans = ans * t % mod;
            continue;
        }
        if(now > 1) tmp.push_back({now, 1});
        for(auto [a, b] : tmp) mul[a] += mul[t] * b;
    }
    cout << ans << "\n";
}
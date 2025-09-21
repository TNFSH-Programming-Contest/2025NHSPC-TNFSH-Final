#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
int fpow(int a, int b, int mod){
    int re = 1;
    while(b){
        if(b & 1)  re = 1LL * re * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return re;
}
int main(){
    int n, k, mod;
    cin >> n >> k >> mod;
    long long sum = 0;
    vector< int > a(k);
    for(int i = 0; i < k; ++i) cin >> a[i], sum += a[i];
    if(sum > n){
        cout << "0\n";
        return 0;
    }
    vector< long long > mul(n + 1), div(n + 1);
    {
        mul[n]++;
        div[sum]++;
        div[n - sum]++;

        mul[n]++;
        div[n - sum]++;
    }
    {
        mul[sum]++;
        for(auto &i : a) div[i]++;
    }
    for(int i = n - 1; i >= 0; --i){
        mul[i] += mul[i + 1];
        div[i] += div[i + 1];
    }
    vector< int > not_p(n + 1);
    vector< int > p;
    {
        for(int i = 2; i <= n; ++i){
            if(!not_p[i]) p.push_back(i);
            for(auto k : p){
                if(k * i > n) break;
                not_p[k * i] = k;
                if(i % k == 0) break;
            }
        }
    }
    int ans = 1;
    for(int i = n; i > 1; --i){
        if(!not_p[i]){
            assert(mul[i] >= div[i]);
            mul[i] -= div[i];
            ans = 1LL * ans * fpow(i, mul[i], mod) % mod;
        }
        else{
            mul[not_p[i]] += mul[i];
            mul[i / not_p[i]] += mul[i];

            div[not_p[i]] += div[i];
            div[i / not_p[i]] += div[i];
            
            mul[i] = div[i] = 0;
        }
    }
    cout << ans << "\n";
}
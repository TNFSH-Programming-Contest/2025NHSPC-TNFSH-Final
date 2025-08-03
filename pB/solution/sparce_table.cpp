#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector< vector< int > > mn(20, vector< int >(n + 1));
    vector< int > dp(n + 1);

    for(int i = 1; i <= n; ++i) cin >> mn[0][i];
    for(int i = 1; i < 20; ++i){
        for(int j = 1; j + (1 << i) - 1 <= n; ++j){
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
        }
    }
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
        if(i - k >= 0){
            int l = __lg(k);
            int val = min(mn[l][i - k + 1], mn[l][i - (1 << l) + 1]);
            dp[i] = max(dp[i], dp[i - k] + val);
        }
	}
	cout << dp[n] << "\n";
}
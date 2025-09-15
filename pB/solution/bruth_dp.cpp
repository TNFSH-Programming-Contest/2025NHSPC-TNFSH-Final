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
	vector< vector< int > > mn(20, vector< int >(n + 1, 1e18));
    vector< int > dp(n + 1, -1e18);

    for(int i = 1; i <= n; ++i) cin >> mn[0][i];
    for(int i = 1; i < 20; ++i){
        for(int j = 1; j + (1 << i) - 1 <= n; ++j){
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
        }
    }
    auto query = [&](int l, int r) -> int {
        if(r - l + 1 < k) return 0;
        int lg = __lg(r - l + 1);
        return min(mn[lg][l], mn[lg][r - (1 << lg) + 1]);
    };
    dp[0] = 0;
	for(int i = 1; i <= n; i++) {
        for(int j = i - 1; j >= 0; --j){
            // cerr << j + 1 << " " << i << " " << query(j + 1, i) << "!\n";
            dp[i] = max(dp[i], dp[j] + query(j + 1, i));
        }
        // cerr << dp[i] << " \n"[i == n];
	}
	cout << dp[n] << "\n";
}
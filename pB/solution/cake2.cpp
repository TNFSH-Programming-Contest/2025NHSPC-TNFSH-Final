#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<utility>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector< int > v(n + 1);
	vector< long long > dp(n + 1);
	deque< pair<int, int> > dq;
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		while(!dq.empty() && dq[0].second <= i - k) dq.pop_front();
		while(!dq.empty() && dq.back().first >= v[i]) dq.pop_back();
		dq.push_back({v[i], i});
		if(!dq.empty() && i - k >= 0) dp[i] = max(dp[i - 1], dp[i - k] + dq[0].first);
	}
	cout << dp[n] << "\n";
}
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
	if(k > 1){
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
	else{
		vector< long long > v(n + 1), tmp{0};
		for(int i = 1; i <= n; ++i){
			cin >> v[i];
			if(i == 1 || ((v[i] ^ tmp.back()) < 0)) tmp.push_back(v[i]);
			else{
				if(v[i] < 0) tmp.back() = min(tmp.back(), v[i]);
				else tmp.back() += v[i];
			}
		}
		int m = (int)tmp.size() - 1;
		tmp.push_back(0);
		vector< int > die(m + 1), L(m + 2), R(m + 2), stk;
		for(int i = 1; i <= m; ++i){
			L[i] = i - 1, R[i] = i + 1;
			if(i > 1 && i < m && tmp[i] >= 0) stk.push_back(i);
		}
		L[0] = 0, R[m + 1] = m + 1;
		// for(int i = 1; i <= m; ++i) cerr << tmp[i] << " \n"[i == m];
		while(!stk.empty()){
			auto cur = stk.back(); stk.pop_back();
			if(die[cur]) continue;
			int l = L[cur], r = R[cur];
			if(l <= 0 || r > m) continue;
			if(min({tmp[l], tmp[cur], tmp[r]}) >= tmp[l] + tmp[cur] + tmp[r]){
				tmp[cur] = min({tmp[l], tmp[cur], tmp[r]});
				die[l] = die[r] = 1;
				L[cur] = L[l];
				R[cur] = R[r];
				R[L[cur]] = cur;
				L[R[cur]] = cur;
				if(L[cur] > 1) stk.push_back(L[cur]);
				if(R[cur] < m) stk.push_back(R[cur]);
			}
		}
		long long ans = 0;
		// cerr << m << " " << die.size() << " " << tmp.size() << " " << L.size() << "??\n";
		for(int i = 1; i <= m; ++i) if(!die[i]) ans += tmp[i];
		cout << ans << "\n";
	}
}
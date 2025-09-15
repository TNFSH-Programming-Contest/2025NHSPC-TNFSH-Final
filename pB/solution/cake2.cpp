#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<utility>
#define SZ(s) ((int)s.size())
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if(k > 1){
		vector< long long > v(n + 1);
		vector< long long > dp(n + 1);
		deque< pair<long long, long long> > dq;
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
        vector< long long > stk;
        for(int i = 1; i <= n; ++i){
			long long x; cin >> x;
			if(x == 0) continue;
			if(x > 0){
				if(!stk.empty() && stk.back() > 0) stk.back() += x;
				else stk.push_back(x);
			}
			else{
				if(!stk.empty() && stk.back() <= 0){
					if(stk.back() <= x) continue;
					else stk.pop_back();
				}
				while(SZ(stk) >= 2 && stk.end()[-2] >= x){
					long long a = stk.back(); stk.pop_back();
					long long b = stk.back(); stk.pop_back();
					if(a + b > 0){
						if(!stk.empty()) stk.back() += a + b; 
						else stk.push_back(a + b);
					}
				}
				if(SZ(stk) >= 2 && stk.back() + x < 0) stk.pop_back();
				else{
					stk.push_back(x);
				}
			}
		}
		long long ans = 0;
		for(auto &k : stk) ans += k;
		cout << ans << "\n";
	}
}
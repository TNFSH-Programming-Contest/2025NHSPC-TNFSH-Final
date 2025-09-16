#include<iostream>
#include<algorithm>
#include<vector>
#include<array>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector< array<int, 2> > v(n);
	vector< array<int, 3> > tmp;
	for(int i = 0; i < n; ++i){
		cin >> v[i][0] >> v[i][1];
		if(v[i][0] < v[i][1]){
			tmp.push_back({v[i][1] - v[i][0], m - v[i][0] - 1, i + 1});
		}
	}
	sort(tmp.begin(), tmp.end());
	vector< vector< int > > ans;
	vector< int > len;
	vector< int > stk;
	int mn = 1e9 + 10;
	for(auto [l, r, i] : tmp){
		if(l > mn && !stk.empty()){
			ans.push_back({});
			len.push_back(mn);
			swap(stk, ans.back());
			mn = 1e9 + 10;
		}
		mn = min(mn, r);
		stk.push_back(i);
	}
	if(!stk.empty()){
		ans.push_back({});
		len.push_back(mn);
		swap(stk, ans.back());
		mn = 1e9 + 10;
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < (int)ans.size(); ++i){
		cout << ans[i].size() << " " << len[i] << "\n";
		for(int j = 0; j < (int)ans[i].size(); ++j){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

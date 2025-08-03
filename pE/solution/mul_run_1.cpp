#include<iostream>
#include<vector>
#include<set>
#define ll long long
using namespace std;

int main() {
	const ll inf = 1e15;
	const ll inf2 = 1e8;
	int n, q;
	cin >> n >> q;
	set< int > need, is_inf;
	vector< ll > v(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
		if(v[i] != 0){
			need.insert(i);
		}
	}
	while(q--){
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1){
			auto it = need.lower_bound(a);
			while(it != need.end() && *it <= b){
				if(v[*it] >= inf2){
					v[*it] = inf;
					is_inf.insert(*it);
					it = need.erase(it);
				}
				else{
					v[*it] *= v[*it];
					++it;
				}
			}
		}
		if(t == 2){
			auto it = need.lower_bound(a);
			while(it != need.end() && *it <= b){
				v[*it] += v[*it];
				if(v[*it] >= inf){
					is_inf.insert(*it);
					it = need.erase(it);
				}
				else ++it;
			}
		}
		if(t == 3){
			{
				auto it = need.lower_bound(a);
				while(it != need.end() && *it <= b){
					v[*it] = 0;
					it = need.erase(it);
				}
			}
			{
				auto it = is_inf.lower_bound(a);
				while(it != is_inf.end() && *it <= b){
					v[*it] = 0;
					it = is_inf.erase(it);
				}
			}
		}
		if(t == 4){
			if(v[a] >= b) cout << "Yes\n";
			else cout << "No\n";
			v[a] = max(0LL, v[a] - b);
			if(v[a] == 0){
				need.erase(a);
			}
		}
	}
}

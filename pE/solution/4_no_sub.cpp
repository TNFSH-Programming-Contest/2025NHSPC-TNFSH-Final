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
	set< int > need_add, need_mul, is_inf;
	vector< ll > v(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
		if(v[i] != 0){
			need_add.insert(i);
			if(v[i] != 1){
				need_mul.insert(i);
			}
		}
	}
	while(q--){
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1){
			auto it = need_mul.lower_bound(a);
			while(it != need_mul.end() && *it <= b){
				if(v[*it] >= inf2){
					v[*it] = inf;
					is_inf.insert(*it);
					need_add.erase(*it);
					it = need_mul.erase(it);
				}
				else{
					v[*it] *= v[*it];
					++it;
				}
			}
		}
		if(t == 2){
			auto it = need_add.lower_bound(a);
			while(it != need_add.end() && *it <= b){
				if(v[*it] == 1) need_mul.insert(*it);
				v[*it] += v[*it];
				if(v[*it] >= inf){
					is_inf.insert(*it);
					need_mul.erase(*it);
					it = need_add.erase(it);
				}
				else ++it;
			}
		}
		if(t == 3){
			{
				auto it = need_add.lower_bound(a);
				while(it != need_add.end() && *it <= b){
					v[*it] = 0;
					need_mul.erase(*it);
					it = need_add.erase(it);
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
			if(v[a] == 1){
				need_mul.erase(a);
			}
			if(v[a] == 0){
				need_add.erase(a);
				need_mul.erase(a);
			}
		}
	}
}

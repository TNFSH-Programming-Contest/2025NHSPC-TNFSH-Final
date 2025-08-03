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
	vector< ll > v(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	while(q--){
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1){
			for(int i = a; i <= b; ++i){
                if(v[i] > inf2) v[i] = inf;
				else v[i] = min(inf, v[i] * v[i]);
            }
		}
		if(t == 2){
			for(int i = a; i <= b; ++i) v[i] = min(v[i] * 2, inf);
		}
		if(t == 3){
			for(int i = a; i <= b; ++i) v[i] = 0;
		}
		if(t == 4){
			if(v[a] >= b) cout << "Yes\n";
			else cout << "No\n";
			v[a] = max(0LL, v[a] - b);
		}
	}
}

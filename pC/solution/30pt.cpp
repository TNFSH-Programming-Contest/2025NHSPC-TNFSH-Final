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
    cout << n << "\n";
	for(int i = 0; i < n; ++i){
		int l, r; cin >> l >> r;
        cout << 1 << " " << max(0, r - l) << "\n";
        cout << i + 1 << "\n";
	}
}

#include<iostream>
#include<vector>
#include<algorithm>
#define all(v) v.begin(), v.end()
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector< int > c(n);
    for(int i = 0; i < n; ++i) cin >> c[i];
    vector< int > num = c;
    sort(all(num));
    num.resize(unique(all(num)) - num.begin());
    int cnt = num.size();
    if(k < cnt - 1){
        cout << "No\n";
    }
    else if(cnt == 1 && k > 0){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
        vector< int > head(cnt);
        for(int i = 0; i < n; ++i){
            c[i] = lower_bound(all(num), c[i]) - num.begin();
            head[c[i]] = i;
        }
        for(int i = 0; i < cnt - 1; ++i){
            cout << head[i] + 1 << " " << head[i + 1] + 1 << "\n";
            --k;
        }
        for(int i = 0; i < n; ++i) if(head[c[i]] != i) {
            if(k > 0){
                cout << i + 1 << " " << head[(c[i] + n - 1) % cnt] + 1 << "\n";
                --k;
            }
            else cout << i + 1 << " " << head[c[i]] + 1 << "\n";
        }
    }
}
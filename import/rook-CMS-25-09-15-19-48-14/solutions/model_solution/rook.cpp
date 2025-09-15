#include<iostream>
using namespace std;
int C[52][52];
int main(){
    int n, k, m;
    cin >> n >> k >> m;
    {
        C[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            C[i][0] = 1;
            for(int j = 1; j <= i; ++j){
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                if(C[i][j] >= m) C[i][j] -= m;
            }
        }
    }
    long long ans = 1;
    for(int i = n; i > n - k; --i) ans = ans * i % m;
    cout << ans * C[n][k] % m << "\n";
}
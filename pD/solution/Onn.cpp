#include<algorithm>
#include<numeric>
#include<iostream>
int compare_numbers(int l, int r);

int v[1002];
int p[1002];
int ask[1002][1002];
int Inv[1002][1002];
using namespace std;
void bob_init(int n){
    for(int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j){
        ask[i][j] = compare_numbers(i, j);
    }
    for(int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j){
        Inv[i][j] = ask[i][j] - ask[i + 1][j] - ask[i][j - 1] + ask[i + 1][j - 1];
    }
    iota(v + 1, v + n + 1, 1);
    sort(v + 1, v + n + 1, [&](int a, int b) -> bool {
        if(a > b) return Inv[b][a];
        else return !Inv[a][b];
    });
    for(int i = 1; i <= n; ++i) p[v[i]] = i;
    
}
int query_from_alice(int a){
    return p[a];
}
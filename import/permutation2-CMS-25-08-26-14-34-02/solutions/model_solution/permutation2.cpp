#include<cmath>
int compare_numbers(int l, int r);

int v[1002];
int ask[1002];
void bob_init(int n){
    v[n] = 1;
	for(int i = n - 1; i > 0; --i){
		ask[i] = compare_numbers(i, n);
		v[i] = ask[i] - ask[i + 1] + 1;
		for(int j = i + 1; j <= n; ++j) if(v[j] >= v[i]) ++v[j];
	}
}
int query_from_alice(int a){
    return v[a];
}
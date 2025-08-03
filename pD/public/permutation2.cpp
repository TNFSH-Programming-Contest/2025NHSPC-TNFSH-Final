#include<vector>
using namespace std;
int compare_numbers(int l, int r);
int v[1010];
void bob_init(int n){
    v[1] = compare_numbers(1, n);
	v[2] = compare_numbers(2, n);
}
int query_from_alice(int a){
    return v[a];
}

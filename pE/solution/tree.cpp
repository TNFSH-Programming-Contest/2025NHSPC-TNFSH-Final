#include<iostream>
#include<vector>
#include<set>
#define ll long long
using namespace std;

const ll inf = 1e15;
const ll inf2 = 1e8;
int n;
struct TREE{
    struct node{
        bool all_zero = 0, need_mul = 0, need_add = 0;
    };
    vector< ll > val;
    vector< node > tree;
    TREE(int N){
        n = N;
        tree.resize(4 * N + 10);
        val.resize(4 * N + 10);
    }
    void pull(int id){
        tree[id].all_zero = tree[id << 1].all_zero && tree[id << 1 | 1].all_zero;
        tree[id].need_mul = tree[id << 1].need_mul || tree[id << 1 | 1].need_mul;
        tree[id].need_add = tree[id << 1].need_add || tree[id << 1 | 1].need_add;
    }
    void get(int id, ll &v){
        v = min(v, inf);
        tree[id].all_zero = (v == 0);
        tree[id].need_mul = (v > 1) && (v < inf);
        tree[id].need_add = (v > 0) && (v < inf);
    }
    void build(int id = 1, int l = 1, int r = n){
        if(l == r){
            cin >> val[l];
            get(id, val[l]);
        }
        else{
            int mid = (l + r) >> 1;
            build(id << 1, l, mid);
            build(id << 1 | 1, mid + 1, r);
            pull(id);
        }
    }
    void modify1(int ql, int qr, int id = 1, int l = 1, int r = n){
        if(l == r){
            if(val[l] > inf2) val[l] = inf;
            else val[l] *= val[l];
            get(id, val[l]);
        }
        else{
            int mid = (l + r) >> 1;
            if(ql <= mid && tree[id << 1].need_mul) modify1(ql, qr, id << 1, l, mid);
            if(qr > mid && tree[id << 1 | 1].need_mul) modify1(ql, qr, id << 1 | 1, mid + 1, r);
            pull(id);
        }
    }
    void modify2(int ql, int qr, int id = 1, int l = 1, int r = n){
        if(l == r){
            val[l] += val[l];
            get(id, val[l]);
        }
        else{
            int mid = (l + r) >> 1;
            if(ql <= mid && tree[id << 1].need_add) modify2(ql, qr, id << 1, l, mid);
            if(qr > mid && tree[id << 1 | 1].need_add) modify2(ql, qr, id << 1 | 1, mid + 1, r);
            pull(id);
        }
    }
    void modify3(int ql, int qr, int id = 1, int l = 1, int r = n){
        if(l == r){
            val[l] = 0;
            get(id, val[l]);
        }
        else{
            int mid = (l + r) >> 1;
            if(ql <= mid && !tree[id << 1].all_zero) modify3(ql, qr, id << 1, l, mid);
            if(qr > mid && !tree[id << 1 | 1].all_zero) modify3(ql, qr, id << 1 | 1, mid + 1, r);
            pull(id);
        }
    }
    bool query(int a, int k, int id = 1, int l = 1, int r = n){
        if(l == r){
            int ret = 1;
            if(val[l] >= k){
                ret = 1;
                val[l] -= k;
            }
            else ret = 0, val[l] = 0;
            get(id, val[l]);
            return ret;
        }
        else{
            int mid = (l + r) >> 1;
            int ok = 0;
            if(a <= mid) ok = query(a, k, id << 1, l, mid);
            else ok = query(a, k, id << 1 | 1, mid + 1, r);
            pull(id);
            return ok;
        }
    }
};
int main() {
    int n, q;
	cin >> n >> q;
	TREE tree(n);
	tree.build();
	while(q--){
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1){
			tree.modify1(a, b);
		}
		if(t == 2){
            tree.modify2(a, b);
		}
		if(t == 3){
			tree.modify3(a, b);
		}
		if(t == 4){
			if(tree.query(a, b)) cout << "Yes\n";
            else cout << "No\n";
		}
	}
}

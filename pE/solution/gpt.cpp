#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// 簡單篩法取得質數
vector<int> sieve_primes(int n) {
    vector<int> primes;
    vector<bool> is_comp(n + 1, false);
    for (int i = 2; i <= n; i++) {
        if (!is_comp[i]) {
            primes.push_back(i);
            if ((int64)i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    is_comp[j] = true;
                }
            }
        }
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    int64 M;
    cin >> N >> K >> M;

    vector<int> C(K);
    int64 s = 0;
    for (int i = 0; i < K; i++) {
        cin >> C[i];
        s += C[i];
    }

    if (s > N) {
        cout << 0 << "\n";
        return 0;
    }

    // cnt[v] = 有多少個 Ci = v
    vector<int> cnt(N + 1, 0);
    for (int v : C) {
        if (v < 0 || v > N) {
            cout << 0 << "\n";
            return 0;
        }
        cnt[v]++;
    }

    // 前綴和 pref[i] = 有多少個 Ci <= i
    vector<int> pref(N + 1, 0);
    pref[0] = cnt[0];
    for (int i = 1; i <= N; i++) pref[i] = pref[i - 1] + cnt[i];

    // S[d] = sum_i floor(Ci / d)
    vector<int64> S(N + 1, 0);
    for (int d = 1; d <= N; d++) {
        int64 total = 0;
        int max_t = N / d;
        for (int t = 0; t <= max_t; t++) {
            int l = t * d;
            int r = min(N, (t + 1) * d - 1);
            if (l > N) break;
            int cnt_interval = pref[r] - (l > 0 ? pref[l - 1] : 0);
            if (cnt_interval) total += 1LL * t * cnt_interval;
        }
        S[d] = total;
    }

    vector<int> primes = sieve_primes(N);
    int64 res = 1 % M;
    int Ns = N - (int)s;

    for (int p : primes) {
        long long e = 0;
        long long d = p;
        while (d <= N) {
            long long term = 2LL * (N / d) - 2LL * (Ns / d) - S[d];
            e += term;
            if (d > N / p) break;
            d *= p;
        }
        if (e > 0) {
            // res *= p^e mod M
            long long cur = 1;
            long long base = p % M;
            long long exp = e;
            while (exp > 0) {
                if (exp & 1) cur = (__int128)cur * base % M;
                base = (__int128)base * base % M;
                exp >>= 1;
            }
            res = (__int128)res * cur % M;
        }
    }

    cout << res % M << "\n";
    return 0;
}

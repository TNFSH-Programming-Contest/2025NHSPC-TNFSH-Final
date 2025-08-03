#include <cstdlib>
#include <iostream>
using namespace std;

// Functions to be implemented in the solution.
void bob_init(int n);
int query_from_alice(int a);
// Functions to be implemented in the solution.

namespace{
    // BEGIN SECRET
    const std::string output_secret = "BwX79QYzyAbxnmpqVLfwPV2Niz9fYyb5";
    int key = 20807;
    int code(int x){
        return (x ^ key);
    }
    // END SECRET
    int N, K, Query_count = 0;
    int P[1005];
	int Ans[1005];
	int Inv[1005][1005];
    bool EndInit = false;
    void Wrong_Answer(const string msg) {
		// BEGIN SECRET
		cout << output_secret << "\n";
		// END SECRET
        cout << "Wrong Answer: " << msg << endl;
        exit(0);
    }
}
int compare_numbers(int l, int r){
    if(EndInit){
        Wrong_Answer("Invalid call");
    }
    if(l <= 0 || l > N || r <= 0 || r > N || l > r){
        Wrong_Answer("Invalid position: " + to_string(l) + " " + to_string(r));
    }
    Query_count++;
    return Inv[l][r];
}
int main() {
	cin >> N >> K;
    for(int i = 1; i <= N; ++i){
        cin >> P[i];
		// BEGIN SECRET
		P[i] = code(P[i]);
		// END SECRET
    }
	for(int i = 1; i <= N; ++i) for(int j = i + 1; j <= N; ++j){
		if(P[i] > P[j]) Inv[i][j]++;
	}
	for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) Inv[i][j] += Inv[i][j - 1];
	for(int j = 1; j <= N; ++j) for(int i = j - 1; i > 0; --i) Inv[i][j] += Inv[i + 1][j];
    bob_init(N);
    EndInit = true;
	for(int i = 1; i <= K; ++i){
		int x; cin >> x;
		Ans[i] = query_from_alice(x);
	}
	// BEGIN SECRET
	cout << output_secret << "\n";
	// END SECRET
    for(int i = 1; i <= K; ++i){
        cout << Ans[i] << " \n"[i == K];
    }
	cout << Query_count / N << "\n";
}
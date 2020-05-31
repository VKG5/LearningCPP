#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int N = 4000;

map<char, char> past;

void gen() {
    past['3'] = '2';
    past['2'] = '1';
    past['1'] = '3';
}

inline int square(int n) {
    n = n * 1LL * n % MOD;

    return n;
}

inline int add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;

    return 0;
}

int dp[N];

int main() {
    gen();
    string S; cin >> S;

    int n = S.size();

    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        assert(S[i] >= '1' && S[i] <= '3');
        assert(S[i - 1] >= '1' && S[i - 1] <= '3');
        dp[i] = INT_MAX;

        for (int j = i - 1; j >= 0; --j) {
            if (past[S[i]] == S[j] && dp[j] != INT_MAX) {
                int DP = dp[j];
                add(DP, square(i - j));
                dp[i] = min(dp[i], DP);
            }
        }
    }

    assert(dp[n - 1] != INT_MAX);
    cout << dp[n - 1] << endl;

    return 0;
}

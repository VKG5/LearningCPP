// Optimizing the GCC compiler
#pragma GCC optimize(3)

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

// Defining multi-line preprocessor macros
// For fast I/P O/P operations, {cin==scanf()}
#define fast {                           \
                ios::sync_with_stdio(0); \
                cin.tie(0);              \
                cout.tie(0);              \
             }

void slove()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> b_value(p + 5);

    for (int i = 1; i <= n; i++)
    {
        vector<int> stacks(k + 3);

        for (int j = 1; j <= k; j++)
        {
          cin >> stacks[j];
          stacks[j] += stacks[j - 1];
        }

        for (int j = p; j >= 1; j--)
        {
            for (int e = j - 1; e >= max(0, j - k); e--)
            {
                b_value[j] = max(b_value[j], b_value[e] + stacks[j - e]);
            }
        }
    }

    cout << b_value[p] << endl;
}
int main()
{
    fast;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        slove();
    }

    return 0;
}

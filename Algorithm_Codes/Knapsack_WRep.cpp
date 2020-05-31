#include<bits/stdc++.h>
using namespace std;

// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n, int val[], int wt[])
{
	// dp[i] is going to store maximum value
	// with knapsack capacity i.
	int dp[W+1];
	memset(dp, 0, sizeof dp);

	// Fill dp[] using above recursive formula
	for (int i=0; i<=W; i++)
	for (int j=0; j<n; j++)
		if (wt[j] <= i)
			dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);

    // Print the array
    for(int i=0; i<=W; i++)
        cout<<dp[i]<<" ";
    cout<<endl;

	return dp[W];
}

// Driver program
int main()
{
	int W = 10;
	int val[] = {9, 14, 16, 30};
	int wt[] = {2, 3, 4, 6};
	int n = sizeof(val)/sizeof(val[0]);

	cout << unboundedKnapsack(W, n, val, wt);

	return 0;
}


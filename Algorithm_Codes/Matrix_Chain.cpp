#include <iostream>

using namespace std;

#define INT_MAX 99999999

// Function to find the most efficient way to multiply
// given sequence of matrices
int MatrixChainMultiplication(int dims[], int n)
{
	// c[i,j] = Minimum number of scalar multiplications (i.e., cost)
	// needed to compute the matrix M[i]M[i+1]...M[j] = M[i..j]
	// The cost is zero when multiplying one matrix
	int c[n + 1][n + 1] = {0};

	for (int i = 1; i <= n; i++)
		c[i][i] = 0;

	for (int len = 2; len <= n; len++) // Subsequence lengths
	{
		for (int i = 1; i <= n - len + 1; i++)
		{
			int j = i + len - 1;
			c[i][j] = INT_MAX;

			for (int k = i; j < n && k <= j - 1; k++)
			{
				int cost = c[i][k] + c[k + 1][j] +
							dims[i - 1]*dims[k]*dims[j];

				if (cost < c[i][j])
					c[i][j] = cost;
			}
		}
	}

	for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
            cout<<c[i][j]<<"\t";

        cout<<endl;
    }

	return c[1][n - 1];
}

// Matrix Chain Multiplication Problem
int main()
{
	// Matrix M[i] has dimension dims[i-1] x dims[i] for i = 1..n
	// input is 10 x 30 matrix, 30 x 5 matrix, 5 x 60 matrix
	int dims[] = { 4, 10, 3, 12, 20, 7 };
	int n = sizeof(dims) / sizeof(dims[0]);

	int ans = MatrixChainMultiplication(dims, n);

	return 0;
}

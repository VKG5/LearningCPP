#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int m,n, sum;
    cout<<"Enter m size of matrix, n power of matrix: ";
    cin>>m>>n;

    vector < vector <int> > matrix(m, vector <int> (m));
    vector < vector <int> > temp_matrix(m, vector <int> (m));

    for(int i=0; i<m; i++)
    {
        cin.ignore();
        for(int j=0; j<m; j++)
            cin>>matrix[i][j];
    }

    // Main program
    for(int t=0; t<n+1; t++)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                sum = 0;
                for(int k=0; k<m; k++)
                {
                    sum += matrix[i][k]*matrix[k][j];
                }
                temp_matrix[i][j] = sum;
            }
        }
    }

    cout<<"\nOutput matrix: \n";
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<temp_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

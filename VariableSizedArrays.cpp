#include<iostream>
#include<vector>

using namespace std;

// Basic program displaying the usage of vectors for multi-dimensional vectors
int main()
{
    int rows, queries, length;

    cin >> rows >> queries;

    // Main program,defining the vector and taking inputs
    vector < vector <int> > arr;

    for (int i = 0; i < rows; i++)
    {
        cin >> length;

        vector <int> temp(length);

        for (int j = 0; j < length; j++)
            cin >> temp[j];

        arr.push_back(temp);
    }

    // Getting the query values
    int i_query[queries], j_query[queries];
    for(int i=0; i<queries; i++)
    {
        cin>>i_query[i]>>j_query[i];
    }

    // Output
    for(int i=0, j=0; i<queries; i++, j++)
        cout<<arr[i_query[i]][j_query[i]]<<"\n";

    return 0;
}

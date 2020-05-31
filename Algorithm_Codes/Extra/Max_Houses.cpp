#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int max_houses(vector <int> arr, int n, int b)
{
    // Sorting the array takes O(nlogn) time
    sort(arr.begin(), arr.end());

    int cnt=0, sum=0;
    for(int i=0; i<n; i++)
    {
        if((sum+arr[i])<b)
        {
            sum+=arr[i];
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    int n, b;
    cin>>n>>b;

    vector <int> A(n);
    for(int i=0; i<n; i++)
        cin>>A[i];

    cout<<"Max number of houses you can buy: "<<max_houses(A, n, b);

    return 0;
}

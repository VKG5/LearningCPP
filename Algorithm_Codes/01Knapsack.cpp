#include<iostream>
#include<vector>
#include<climits>

using namespace std;

typedef pair <int, int> iPair;
#define endl "\n"

// For testing
void print_vector(vector <iPair> arr, int n)
{
    for(int i=0; i<n ; i++)
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
}

// 0-1 Knapsack
int max_rating(vector <iPair> arr, int n, int tot_size)
{
    if(tot_size<0)
        return INT_MIN;

    if(n<0 || tot_size==0)
        return 0;

    int include = arr[n].second + max_rating(arr, n-1, tot_size-arr[n].first);

    int exclude = max_rating(arr, n-1, tot_size);

    return max(include, exclude);
}

int main()
{
    int n, c, r, limit;
    cin>>n>>limit;

    // First element is the cost, second the rating
    vector <iPair> B;
    for(int i=0; i<n; i++)
    {
        cin>>c>>r;
        B.push_back(make_pair(c, r));
    }

    // print_vector(B, n);
    cout<<endl<<"The maximum rating is: "<<max_rating(B, n-1, limit);

    return 0;
}

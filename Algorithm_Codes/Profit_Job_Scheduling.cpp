#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(const pair<int, int> &i, const pair<int, int> &j)
{
    return i.second>j.second;
}

void print_array(vector < pair<int, int> > arr, int n)
{
    // Printing the array
    for(int i=0; i<n; i++)
    {
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
}

int max_profit(vector < pair<int, int> > arr, int n)
{
    // Sorting the array according to profit
    sort(arr.begin(), arr.end(), compare);

    // The sorted array
    print_array(arr, n);

    // Making a temp array
    int temp[n+1]={0};
    int profit = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=arr[i-1].first-1; j>=0; j--)
        {
            if(temp[j] == 0)
            {
                temp[j] = arr[i-1].second;
                profit+=temp[j];
                break;
            }
        }
    }

    cout<<"Maximum Profit Job schedule: ";
    // Printing the array
    for(int i=0; i<=n; i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;

    return profit;
}

int main()
{
    int n = 10;

    int deadline[] = { 9, 2, 5, 7, 4, 2, 5, 7, 4, 3 };
    int profit[] = { 15, 2, 18, 1, 25, 20, 8, 10, 12, 5};

    vector < pair<int, int> > arr(n);

    // First deadline, second Profit
    for(int i=0; i<n; i++)
    {
        arr[i] = make_pair(deadline[i], profit[i]);
    }

    cout<<"Max profit: "<<max_profit(arr, n)<<endl;

    return 0;
}

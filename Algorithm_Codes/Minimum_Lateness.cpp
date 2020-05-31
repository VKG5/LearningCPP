#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(const pair<int, int> &i, const pair<int, int> &j)
{
    return i.second<j.second;
}

void print_array(vector < pair<int, int> > arr, int n)
{
    cout<<"Time  Deadline\n";
    // Printing the array
    for(int i=0; i<n; i++)
    {
        cout<<arr[i].first<<"\t"<<arr[i].second<<endl;
    }
}

int min_lateness(vector < pair<int, int> > arr, int n)
{
    // Sorting the array according to earliest deadline
    sort(arr.begin(), arr.end(), compare);

    // The sorted array
    print_array(arr, n);

    // Making a temp array
    int tot_time = 0, lateness=0;

    for(int i=0; i<n; i++)
    {
        tot_time+=arr[i].first;

        // If the current time is greater than the deadline
        if(tot_time>arr[i].second)
            lateness = tot_time-arr[i].second;
    }

    return lateness;
}

int main()
{
    int n = 2;

    int execute[] = {1, 10};
    int deadline[] = {2, 10};

    vector < pair<int, int> > arr(n);

    // First time taken to execute, second deadline
    for(int i=0; i<n; i++)
    {
        arr[i] = make_pair(execute[i], deadline[i]);
    }

    cout<<"Lateness: "<<min_lateness(arr, n)<<endl;

    return 0;
}


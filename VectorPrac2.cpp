#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    // To make an array and place the elements of the array in the vector
    int arr[] = {10,2,2,3,5,7,2,12,5,4,15,6};
    vector <int> vec(arr, arr+12);

    // To sort the vector
    sort(vec.begin(), vec.end());

    // To make an iterator of the vector
    vector<int>::iterator lower, upper;

    lower = lower_bound(vec.begin(), vec.end(), 2);
    upper = upper_bound(vec.begin(), vec.end(), 2);

    // lower - vec.begin() ~ Gives the "index" of the first occurence of 2
    cout<<"The lower index of 2 is: "<<(lower - vec.begin());

    // upper - vec.begin() ~ Gives the "position" of the last occurence of 2
    // upper - vec.begin() - 1 ~ Gives "index" for the same
    cout<<"\nThe upper index of 2 is: "<<(upper - vec.begin())-1;

    return 0;
}

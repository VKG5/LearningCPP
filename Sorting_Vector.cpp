#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int size;
    cin>>size;

    vector <int> arr(size);

    for(int i=0; i<size; i++)
        cin>>arr[i];

    sort(arr.begin(), arr.end());

    // for(auto i=arr.begin(); i!=arr.end(); i++)
    //    cout<<*i<<" ";

    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";

    return 0;
}

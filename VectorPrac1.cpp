#include <vector>
#include <iostream>

using namespace std;

// Basics of Vectors STL
int main()
{
    int len, del, range[2];
    cin>>len;

    vector <int> arr(len);

    for(int i=0; i<len; i++)
        cin>>arr[i];

    cin>>del;

    for(int i=0; i<2; i++)
        cin>>range[i];

    arr.erase(arr.begin()+(del-1));
    arr.erase(arr.begin()+(range[0]-1), arr.begin()+(range[1]-1));

    cout<<arr.size()<<"\n";
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";

    return 0;
}


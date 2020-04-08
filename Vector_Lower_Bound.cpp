#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int size, comp, num;
    cin>>size;

    vector <int> vec(size);

    for(auto i=vec.begin(); i!=vec.end(); i++)
        cin>>*i;

    sort(vec.begin(), vec.end());

    cin>>comp;
    vector<int>::iterator lower;

    for(int i=0; i<comp; i++)
    {
        cin>>num;
        lower = lower_bound(vec.begin(), vec.end(), num);

        // To print the positions of current or closest element
        if(vec[lower-vec.begin()]==num)
            cout<<"Yes "<<(lower-vec.begin())+1<<"\n";

        else
            cout<<"No "<<(lower-vec.begin())+1<<"\n";
    }

    return 0;
}

#include<iostream>
#include<map>

// Unordered_map is just an unordered sequence of the map
// Map is in a sorted sequence, both work nearly the same
using namespace std;

// Basic working of a map
int main()
{
    map <int, int> my_list;

    // To increment the key value from a pre-calculated list
    for(int i=0; i<10; i++)
    {
        if(my_list.find(i)==my_list.end())
            my_list[i]++;
    }

    // For accessing the members of the list, first is the "KEY" second is the "VALUE"
    // Similar to dictionary in python
    for(auto i=my_list.begin(); i!=my_list.end(); i++)
        cout<<i->first<<" "<<i->second<<endl;

    return 0;
}

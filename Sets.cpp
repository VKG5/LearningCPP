#include<iostream>
#include<set>

using namespace std;

int main()
{
    set <int> s;
    int n, x, y;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>y>>x;

        switch(y)
        {
            case 1: s.insert(x);
                    break;

            case 2: s.erase(x);
                    break;

            case 3: set<int>::iterator itr = s.find(x);

                    if(itr!=s.end())
                        cout<<"Yes";

                    else
                        cout<<"No";

                    break;
        }
    }

    return 0;
}

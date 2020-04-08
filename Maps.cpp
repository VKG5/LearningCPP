#include<iostream>
#include<map>

using namespace std;

int main()
{
    map <string, int> m;

    int n, y, z;
    string x;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>z;

        switch(z)
        {
            case 1: cin>>x>>y;

                    if(m.find(x)!=m.end())
                        m[x]+=y;

                    else
                        m.insert(make_pair(x,y));

                    break;

            case 2: cin>>x;
                    m.erase(x);
                    break;

            case 3: cin>>x;
                    map<string, int>::iterator itr = m.find(x);

                    if(itr!=m.end())
                        cout<<m[x]<<"\n";

                    else
                        cout<<0<<"\n";

                    break;
        }
    }

    return 0;
}

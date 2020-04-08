#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s = "07:00:54PM";

    // To check substring
    if(s.find("PM")!=string::npos)
        cout<<"It's evening motherf****r!";

    // Replacing a substring
    s.replace(s.begin()+8,s.end(),"");
    cout<<"\n"<<s;

    return 0;
}

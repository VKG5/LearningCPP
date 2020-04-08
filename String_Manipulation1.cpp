#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    string s = "07:00:57";

    stringstream ss(s);
    string tok;
    int converted;
    char delimiter=':';

    while(getline(ss,tok,delimiter))
    {
        stringstream basic(tok);
        basic >> converted;
    }

    cout<<converted;

    return 0;
}

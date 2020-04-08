#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// A function for returning the string as integer or any other data type.
vector <int> split(string str, char delimiter)
{
    vector <int> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    int temp;

    while(getline(ss, tok, delimiter))
    {
        // Pushing the stream value as a string
        // internal.push_back(tok);

        // Pushing the stream value into an integer
        stringstream basic(tok);
        basic >> temp;
        internal.push_back(temp);
    }

    return internal;
}

int main()
{
    string line;

    getline(cin, line);

    vector <int> sep = split(line, ' ');

    int sum = 0;
    for(auto t : sep)
        sum+=t;

    cout<<sum;

    return 0;
}


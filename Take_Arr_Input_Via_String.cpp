#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

// A function for returning the string as integer or any other data type.
vector <long long int> split(string str, char delimiter)
{
    vector <long long int> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    long long int temp;

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

    vector <long long int> arr = split(line, ' ');

    sort(arr.begin(), arr.end());

    long long int sum_min = 0, sum_max = 0;

    for(long long int i=0; i<arr.size()-1; i++)
        sum_min+=arr[i];

    for(long long int i=arr.size()-1; i>0; i--)
        sum_max+=arr[i];

    cout<<sum_min<<" "<<sum_max;

    return 0;
}



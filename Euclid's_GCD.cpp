// <algorithm> includes the various algorithms
#include<iostream>
#include<algorithm>

using namespace std;

// This is for calculating the GCD of two numbers using the in-built function
// EUCLID'S GCD Algorithm
// Complexity - O(log2n) ( log2n -> log(n) to the base 2 ), n - upper limit of (a,b)
// For details - https://www.quora.com/What-is-the-time-complexity-of-Euclids-GCD-algorithm
int main()
{
    int a,b;
    cin>>a>>b;

    cout<<__gcd(a,b);

    return 0;
}

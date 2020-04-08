#include<iostream>
#include<cstring>

using namespace std;

// Sieve Of Eratosthenes Algorithm
// Reference - https://www.geeksforgeeks.org/sieve-of-eratosthenes/
int prime_divisor(int n)
{
    bool prime_array[n];
    memset(prime_array, true, sizeof(prime_array));

    // Checking prime or not
    for(int p=2; p*p<=n; p++)
    {
        if(prime_array[p])
        {
            for(int i=p*p; i<=n; i+=p)
                prime_array[i]=false;
        }
    }

    // To get the prime divisors for the particular number
    int cnt=0;
    for(int i=2; i<=n; i++)
        if(prime_array[i] && n%i==0)
            cout<<i<<" ";

    return cnt;
}

int main()
{
    divisor(100001);

    return 0;
}

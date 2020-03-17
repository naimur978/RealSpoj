#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define N 1000000007L; // prime modulo value

long long exponentiation(long base, long exp)
{
    long t = 1L;
    while (exp > 0)
    {

        // for cases where exponent
        // is not an even value
        if (exp % 2 != 0)
            t = (t * base) % N;

        base = (base * base) % N;
        exp /= 2;
    }
    return t % N;
}

// Driver code
int main()
{
    ll n;

    cin>>n;

    while(n--){
        ll a;

        cin>>a;

        int cnt =1;

        while(a!=0){
            a/=2;
            cnt++;
        }

        ll base = 2;
        ll exp = cnt;

        ll modulo = exponentiation(base, exp);
        cout << modulo-1<<endl;
    }

    return 0;
}

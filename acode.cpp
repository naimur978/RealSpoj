#include <bits/stdc++.h>
using namespace std;

// A Dynamic Programming based function to count decodings & it's kinda permutation
int countDecodingDP(string digits, int n)
{
    int count[n+1];
    count[0] = 1;  //by default i have to store count[0] and count[1]
    count[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;
        //when it times to count single number as alphabet
        // 0 will not be allowed for making single number to alphabet
        if (digits[i-1] > '0')
            count[i] = count[i-1];

        //when it times to count double number as alphabet
        //at time of double number first can be either 1 or 2, in time of 1, later number can be anything. but
        //in time of 2, later number must be less than 7,as alphabets limit is 26
        if (digits[i-2] == '1' || (digits[i-2] == '2' && digits[i-1] < '7') )
            count[i] += count[i-2];
    }

    return count[n];
}


int main()
{
    string digits;

    while(1)
	{
	    getline(cin,digits);
		if(digits[0]=='0') break;
		int n = digits.size();
        cout <<countDecodingDP(digits, n)<<endl;

	}

	return 0;

}

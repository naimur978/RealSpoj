#include <bits/stdc++.h>
using namespace std;
int lcs(string s)
{
    string r = s;
    reverse(r.begin(),r.end());
    int n = s.size();
    int dp[n+1][n+1];
    for(int i=0; i<n; ++i)
    {
        dp[i][0]=dp[0][i]=0;
    }

    for(int i=1; i<n+1; ++i)
    {
        for(int j=1; j<n+1; ++j)
        {
            if(s[i-1]==r[j-1])
            {
                dp[i][j]=  dp[i-1][j-1]+1;
            }
            else
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return n-dp[n][n];
}
int main()
{
    //freopen("abc.txt","r",stdin);
    int t;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        cout<<lcs(s)<<endl;;
    }


}

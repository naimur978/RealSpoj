#include <bits/stdc++.h>

using namespace std;

int c,n;
long long int a[100000];

int check(long long int x)
{
	int cowsp=1;
	long long int lastp=a[0];
	for(int i=0;i<n;i++)
	{
	    ///cout<<"fsdf "<<" "<<a[i]<<" "<<lastp<<" "<<x<<endl;
		if(a[i]-lastp>=x)
		{
			cowsp++;
			lastp=a[i];
			if(cowsp==c)return 1;
		}
	}
	return 0;
}
long long int binarysearch()
{
	long long int start=0;  //binary search start with 0
	long long int end=a[n-1];
	//cout<<"fsdf "<<start<<" "<<end<<endl;
	while(end-start>1)
	{
		long long int mid=start+(end-start+1)/2;
		//cout<<"fsdf "<<" "<<start<<" "<<end<<" "<<mid<<endl;
		if(check(mid)==1)  //c(3) ke 2 and 4 er vitor felte binary search use korsi
		{
			start=mid;
		}
		else
		{
			end=mid;
		}
	}

	return start;
}
int main()
{
    //freopen("abc.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&c);
		for (int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		printf("%lld\n",binarysearch());
	}
}

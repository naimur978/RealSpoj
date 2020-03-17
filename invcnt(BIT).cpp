#include <bits/stdc++.h>
using namespace std;

#define ll long long

int tree[10000005];
int maxVal;

//breaking segments
int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        //cout<<"idx "<<idx<<" sum "<<sum<<endl;
        idx -= (idx & -idx);
        //cout<<"after idx "<<idx<<endl;
    }
    return sum;
}

//updating and merging segment
void update(int idx, int val){
    while(idx <= maxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}


int main(){
    //freopen("abc.txt","r",stdin);
    ll t;
    scanf("%lld",&t);
    while(t--){
   memset(tree , 0 , sizeof (tree));
   ll n;
   scanf("%lld",&n);
   int a[n];
   maxVal=0;
   for(int i=0;i<n;i++){
   scanf("%d",&a[i]);

   maxVal=max(maxVal,a[i]);
   }
   ll sum=0;
   for(int i=n-1;i>=0;i--)
   {
       sum+=read(a[i]-1);
      // cout<<"sum "<<a[i]-1<<endl;
       update(a[i],1);
       }
    cout<<sum<<endl;
    }

return 0;
}

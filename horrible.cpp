#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN  = 2e5+7;

ll tree[5*maxN];
ll lazy[5*maxN];

//init lagbe na , kono table banabo na 
void update(int node ,int left ,int right, int lq, int rq , int x)
{
	if(lazy[node])
	{
		tree[node] += (right-left+1)*1ll*lazy[node]; //e-b+1 ///111 carry variable 
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	// no overlap
	if( lq > right || rq < left )
		return;
	//total overlap
	if( left >= lq && right <= rq )
	{
		tree[node] += (right-left+1)*1ll*x;
		if(left != right)
		{
			lazy[2*node] += x;
			lazy[2*node+1] += x;
		}
		lazy[node] = 0;
		return;
	}
	// partial overlap

	int mid = (left + right) / 2;
	update(2*node,left,mid,lq,rq,x);
	update(2*node+1,mid+1,right,lq,rq,x);

	tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(int node,int left , int right, int lq, int rq)
{
	if(lazy[node])
	{
		tree[node] += (right-left+1)*1ll*lazy[node];
		if(left != right)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	// no overlap
	if( lq > right || rq < left )
		return 0;
	//total overlap
	if( left >= lq && right <= rq )
	{
		return tree[node];
	}
	int mid = (left + right) / 2;
	return query(2*node,left,mid,lq,rq) + query(2*node+1,mid+1,right,lq,rq);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--)
	{
		for(int i = 0; i < 5*maxN; i++)
		{
			tree[i] = lazy[i] = 0;
		}
		int n , q; cin >> n >> q;
		while(q--)
		{
			int tp; cin >> tp;
			if(tp == 0 )
			{
				int l , r , x; cin >> l >> r >> x;
				update(1,0,n-1,l-1,r-1,x);
				//add x in [l,r]
				//update
			}
			else if(tp == 1)
			{
				int l , r; cin >> l >> r;
				cout << query(1,0,n-1,l-1,r-1) << "\n";
				// query the sum in [l,r]
			}
		}
	}
    return 0;
}

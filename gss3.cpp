#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5+7;
int a[maxN];


struct node
{
	int best;
	int prefixBest;
	int suffixBest;
	int sum;
	node()
	{
		best = prefixBest = suffixBest = sum = 0;
	}
	node(int val)
	{
		best = prefixBest = suffixBest = sum = val;
	}
	void merge(node left , node right)
	{
	    //cout<<"left "<<sum<<" "<<left.prefixBest<<" "<<left.sum<<" "<<right.suffixBest<<endl;
		//cout<<"right "<<sum<<" "<<right.suffixBest<<" "<<right.sum<<" "<<left.suffixBest<<endl;
		sum = left.sum + right.sum;
		prefixBest = max(left.prefixBest , left.sum + right.prefixBest);
		suffixBest = max(right.suffixBest, right.sum + left.suffixBest);
		//cout<<"abc "<<prefixBest<<" "<<suffixBest<<endl;
		best = max( left.best , max ( right.best , left.suffixBest + right.prefixBest));
	}

}tree[4*maxN];  //four parameter

//to initiate the table
void init(int id ,int left ,int right)
{
	if(left == right)
	{
		tree[id] = node(a[left]);
		return;
	}
	int mid = (left + right)/2;
	init(2*id,left,mid);
	init(2*id+1,mid+1,right);

	tree[id] = node();
	tree[id].merge(tree[2*id],tree[2*id+1]);
}

void update(int id ,int left , int right, int index , int val)
{
	if(left == right)
	{
		tree[id] = node(val);
		return;
	}
	int mid = (left + right)/2;

	if(index <= mid)
		update(2*id,left,mid,index,val);
	else
		update(2*id+1,mid+1,right,index,val);

	tree[id] = node();
	tree[id].merge(tree[2*id],tree[2*id+1]);
}


node query(int id , int left , int right ,int lq ,int rq)
{
	if(left > rq || right < lq )
	{
		node n(-1000000);   //anything lower value
		n.sum = 0;
		return n;
	}

	if(left >= lq && right <= rq)
	{
		return tree[id];
	}
	int mid = (left + right)/2;

	node l_node = query(2*id,left,mid,lq,rq);
	node r_node = query(2*id+1,mid+1,right,lq,rq);

	node parent = node();
	parent.merge(l_node,r_node);
	return parent;
}
int main()
{
	//freopen("abc.txt","r",stdin);

	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	init(1,0,n-1);

	int m;
	scanf("%d",&m);  //if 0 there will be a change and if not there will be 1
	while(m--)
	{
		int tp ;
		scanf("%d",&tp);
		if(tp == 1)
		{
			int l , r;
			scanf("%d%d",&l,&r);
			l--; r--;
			printf("%d\n",query(1,0,n-1,l,r).best);
		}
		if(tp == 0)
		{
			int x , val;
			scanf("%d%d",&x,&val);
			x--;
			update(1,0,n-1,x,val);
			//update  //we updte -3 in place of number 3 #index
		}

	}
	return 0;
}

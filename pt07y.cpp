 #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
    vector < int > V[10002];
    int visit[10002];
    int cnt,flag;
    void dfs(int u,int p)
    {

        visit[u]=1;
        cnt++;

        for(int i=0;i<V[u].size();i++)
        {
            if(visit[V[u][i]]==0)
                dfs(V[u][i],u);

            else if(V[u][i]!=p)
                flag=1;

        }
    }
    int main()
    {
       //freopen("abc.txt","r",stdin);
        int i,j,n,m,u,v;
        cin>>n>>m;
        int a[10002]={0};
        for(i=0;i<m;i++)
            {
                cin>>u>>v;

                V[u].push_back(v);
                V[v].push_back(u);
            }
        dfs(u,-1);      //last u = 2

        if((cnt!=n) || flag)
            cout<<"NO";
        else
            cout<<"YES";

    return 0;
    }

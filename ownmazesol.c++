        #include<bits/stdc++.h>
        using namespace std;
        typedef long long ll;
        ll n,m,k,i,j;
        bool vis[505][505];
        char arr[505][505];
        ll dx[]={-1,0,1,0};
        ll dy[]={0,1,0,-1};
        void dfs(ll x,ll y)
        {
            if(x<0 || x>=n||y<0||y>=m)
            return;
            if(arr[x][y]!='.')
            return;
            if(vis[x][y]==true)
            return ;
            vis[x][y]=true;
            for(ll i=0;i<4;i++)
            {
                ll u=x+dx[i];
                ll v=y+dy[i];
                dfs(u,v);
            }
            if(arr[x][y]=='.' and k)arr[x][y]='X',k--;
            return;
        }
        int main()
        {
            cin>>n>>m>>k;
            for(ll i=0;i<n;i++)
            cin>>arr[i];
            for(ll i=0;i<n && k;i++)
            for(ll j=0;j<m && k;j++)
            dfs(i,j);
            for(ll i=0;i<n;i++)
            {for(ll j=0;j<m;j++)
            cout<<arr[i][j];cout<<"\n";}
            return 0;
        }

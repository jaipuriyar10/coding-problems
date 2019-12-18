    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    int main()
    {
        ll t;
        cin>>t;
        while(t--)
        {
            ll n,m;
            cin>>n>>m;
            vector<ll> v1[n+1];
            for(ll i=1;i<=m;i++)
            {
                ll x,y;
                cin>>x>>y;
                v1[x].push_back(y);
                v1[y].push_back(x);
            }
            queue<ll> q;
            q.push(1);
            ll level[n+1];
            memset(level,0,sizeof(level));
            bool vis[n+1];
            memset(vis,false,sizeof(vis));
            vis[1]=true;
            while(!q.empty())
            {
                ll p=q.front();
                q.pop();
                for(ll i=0;i<v1[p].size();i++)
                {
                    if(vis[v1[p][i]]==false)
                    {
                        vis[v1[p][i]]=true;
                        level[v1[p][i]]=level[p]+1;
                        q.push(v1[p][i]);
                        if(v1[p][i]==n)
                        goto end;
                    }
                }
            }
            end:
            cout<<level[n]<<"\n";
        }
        return 0;
    }

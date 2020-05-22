#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v1[1000005];
bool vis[1000005];
ll cc;
ll conn[1000005];
void dfs(ll x)
{
    vis[x]=true;
    conn[x]=cc;
    for(ll i=0;i<v1[x].size();i++)
    {
        if(vis[v1[x][i]]==false)
        dfs(v1[x][i]);
    }
    return ;
}
int main()
{
    ll t,x,y;
    string str;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n;i++)
        vis[i]=false,v1[i].clear(),conn[i]=0;
        vector<pair<ll,ll>>vp;
        for(ll i=1;i<=m;i++)
        {
            cin>>x>>str>>y;
            if(str=="=")
            {
                v1[x].push_back(y);
                v1[y].push_back(x);
            }
            else
            {
                vp.push_back({x,y});
            }
        }
        cc=0;
        for(ll i=1;i<=n;i++)
        {
            cc++;
            if(vis[i]==false)
            dfs(i);
        }
        bool flag=true;
        for(auto it=vp.begin();it!=vp.end();it++)
        {
            ll a=it->first;
            ll b=it->second;
            if(conn[a]==conn[b])
            {flag=false;
            break;
            }
        }
        if(flag)
        cout<<"YES"<<"\n";
        else
        cout<<"NO"<<"\n";
    }
    return 0;
}

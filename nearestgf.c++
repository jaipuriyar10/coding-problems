#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    vector<ll> v1[n+1];
    for(ll i=0;i<n-1;i++)
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
    level[1]=1;
    vis[1]=true;
    while(!q.empty())
    {
        ll p=q.front();
        q.pop();
        for(ll i=0;i<v1[p].size();i++)
        {
            if(vis[v1[p][i]]==false)
            {
                level[v1[p][i]]=level[p]+1;
                vis[v1[p][i]]=true;
                q.push(v1[p][i]);
            }
        }
    }
    ll Q;
    cin>>Q;
    vector<pair<ll,ll>> vp;
    while(Q--)
    {
        ll x;
        cin>>x;
        vp.push_back(make_pair(level[x],x));
    }
    sort(vp.begin(),vp.end());
    cout<<vp[0].second<<"\n";
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll moves[30];
        memset(moves,-1,sizeof(moves));
        for(ll i=0;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            moves[x]=y;
        }
        queue<pair<ll,ll>> q;
        q.push({0,0});
        bool vis[30];
        memset(vis,false,sizeof(vis));
        vis[0]=true;
        pair<ll,ll> p;
        while(!q.empty())
        {
            p=q.front();
            if(p.first==29)
            break;
            q.pop();
            for(ll j=p.first+1;j<=p.first+6 and j<30;j++)
            {
                if(!vis[j])
                {
                    pair<ll,ll> p2;
                    p2.second=p.second+1;
                    vis[j]=true;
                    if(moves[j]!=-1)
                    p2.first=moves[j];
                    else
                    p2.first=j;
                    q.push(p2);
                }
            }
        }
        cout<<p.second<<"\n";
    }
    return 0;
}

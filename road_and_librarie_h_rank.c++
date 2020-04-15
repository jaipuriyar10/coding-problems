problem: https://www.hackerrank.com/challenges/torque-and-development/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
//#include<math.h>
typedef long long ll;
vector<ll> v1[100006];
using namespace std;
bool vis[100006];
void dfs(ll x,ll &cnt)
{
    if(vis[x]==false)
    vis[x]=true;
    cnt++;
    for(ll i=0;i<v1[x].size();i++)
    {
        if(vis[v1[x][i]]==false)
        dfs(v1[x][i],cnt);
    }
}        

int main()
{
    ll q;
    cin>>q;
    while(q--)
    {
        ll n,m,cl,cr;
        cin>>n>>m>>cl>>cr;
        memset(vis,false,sizeof(vis));
        for(ll i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;
            v1[x].push_back(y);
            v1[y].push_back(x);
        }
        ll sum=0;
        for(ll i=1;i<=n;i++)
        {
            int cnt=0;
            if(vis[i]==false)
            {
                dfs(i,cnt);
                sum+=((cnt-1)*cr+cl);
            }
        }
        cout<<sum<<"\n";
        for(ll i=1;i<=n;i++)
        v1[i].clear();
    }
    return 0;
}

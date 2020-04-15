problem:https://www.hackerrank.com/challenges/find-the-nearest-clone/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
vector<ll> v1[1000005];
bool vis[1000005];
ll col[1000005];
ll c;
ll z;
void bfs(ll x)
{
    memset(vis,false,sizeof vis);
    vis[x]=true;
    queue<pair<ll,ll>> q;
    q.push({x,0});
    while(!q.empty())
    {
        pair<ll,ll> p=q.front();
        q.pop();
        for(ll i=0;i<v1[p.first].size();i++)
        {
            if(vis[v1[p.first][i]]==false)
            {   
                if(col[v1[p.first][i]]==z)
                {
                    c=p.second+1;
                    //vis[v1[p.first][i]]=true;
                    return ;
                }
                else
                {
                    q.push({v1[p.first][i],p.second+1});
                    vis[v1[p.first][i]]=true;
                }


            }
        }
    }
}
int main()
{
    ll n,m,x,y;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        cin>>x>>y;
        x-=1;
        y-=1;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    memset(col,0,sizeof col);
    for(ll i=0;i<n;i++)
    cin>>col[i];
    
    cin>>z;
    ll ans=1e9+7;
    for(ll i=0;i<n;i++)
    {
        
        if(col[i]==z)
        {
            c=1e9+7;
            bfs(i);
            ans=min(ans,c);
    
        }
    }
    //cout<<ans<<" ";
    if(ans==(1e9+7))
    ans=-1;
    cout<<ans<<"\n";
    return 0;

}

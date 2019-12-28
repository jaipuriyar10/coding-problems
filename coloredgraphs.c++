#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> v1[105];
bool vis[105];
int dfs(ll u,ll col,ll v)
{
	vis[u]=1;
	if(u==v)
	return 1;
	for(ll i=0;i<v1[u].size();i++)
	{
		pair<ll,ll> p=v1[u][i];
		if(vis[p.first]==false and p.second==col)
		if(dfs(p.first,col,v))return 1;
	}
	return 0;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		v1[x].push_back({y,z});
		v1[y].push_back({x,z});
	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		ll ans=0;
		for(ll i=1;i<=100;i++)
		{
			memset(vis,false,sizeof(vis));
			if(dfs(x,i,y))
			ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
			

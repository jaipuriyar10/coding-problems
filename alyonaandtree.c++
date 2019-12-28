#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> v1[100005];
bool vis[100005];
ll ans;
unordered_map<ll,ll> ma;
	
void dfs(ll node,ll pnode,ll d,ll er)
{
	if(d>ma[node])
	er=1;
	ans+=er;
	for(ll i=0;i<v1[node].size();i++)
	{
		if(v1[node][i].first!=pnode)
		dfs(v1[node][i].first,node,max(d,0ll)+v1[node][i].second,er);
	}
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		ma[i+1]=x;
	}
	for(ll i=2;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		v1[i].push_back({x,y});
		v1[x].push_back({i,y});
	}	
	dfs(1,0,0,0);
	cout<<ans<<"\n";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[100005];
vector<ll> v2(1000005);
vector<ll> v1[100005];
ll dfs(ll &cnt,ll x)
{
	vis[x]=true;
	cnt++;
	for(ll i=0;i<v1[x].size();i++)
	{
		if(vis[v1[x][i]]==false)
		{
			dfs(cnt,v1[x][i]);
		}
			v2[x]=max(v2[x],v2[v1[x][i]]+1);
		
	}
	return cnt;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		v1[x].push_back(y);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ll cnt=0;
		if(vis[i]==false)
		{
			ll res=dfs(cnt,i);
			ans=max(ans,res);
		}
	}
	cout<<*max_element(v2.begin(),v2.end())<<"\n";
	return 0;
}

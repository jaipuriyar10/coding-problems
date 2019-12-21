#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[500];
vector<ll> v1[500];
void dfs(ll x)
{
	vis[x]=true;
	for(ll i=0;i<v1[x].size();i++)
	{
		if(vis[v1[x][i]]==false)
		dfs(v1[x][i]);
	}
}
int main()
{
	ll n,m;
	cin>>n>>m;
	ll ans=0;
	set<ll>st;
	memset(vis,false,sizeof(vis));
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll a;
			cin>>a;
			st.insert(a);
			v1[i].push_back(n+a);
			v1[n+a].push_back(i);
		}
	}
	ll l=st.size();
	if(l==0)
	cout<<n;
	else
	{for(ll j=1;j<=n;j++)
	if(!vis[j]){ans++;dfs(j);}
	cout<<(ans-1)<<"\n";}
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
	
                              

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
		ll dist[n][m];
		ll arr[n][m];
		for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
		{
			cin>>arr[i][j];
			dist[i][j]=INT_MAX;
		}
		queue<pair<ll,ll>> q;
		pair<ll,ll>p;
		q.push(make_pair(0,0));
		dist[0][0]=arr[0][0];
		ll dx[]={0,0,1,-1};
		ll dy[]={1,-1,0,0};
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			ll x=p.first;
			ll y=p.second;
			for(ll i=0;i<4;i++)
			{
				ll u=x+dx[i];
				ll v=y+dy[i];
				if(u>=0 and u<n and v>=0 and v<m and dist[u][v]>dist[x][y]+arr[u][v])
				{
					dist[u][v]=dist[x][y]+arr[u][v];
					q.push(make_pair(u,v));
				}
			}
		}
		ll a,b,z;
		cin>>a>>b>>z;
		if(dist[a-1][b-1]<=z)
		{
			cout<<"YES"<<"\n";
			cout<<abs(dist[a-1][b-1]-z)<<"\n";
		}
		else
		cout<<"NO"<<"\n";
	}
	return 0;
}

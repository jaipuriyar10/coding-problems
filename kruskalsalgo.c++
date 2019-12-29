/*#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max=1e5+5;
ll id[Max],nodes,edges;
pair<ll,pair<ll,ll>> p[Max];
void init()
{
	for(ll i=0;i<Max;i++)
	id[i]=i;
}
ll root(ll i)
{
	while(id[i]!=i)
	{
		id[i]=id[id[i]];
		i=id[i];
	}
	return i;
}
void union1(ll x,ll y)
{
	ll p=root(x);
	ll q=root(y);
	id[p]=id[q];
}
ll kruskal(pair<ll,pair<ll,ll>> p[])
{
	ll x,y;
	ll cost,mincost=0;
	for(ll i=0;i<edges;i++)
	{
		x=p[i].second.first;
		y=p[i].second.second;
		cost=p[i].first;
		if(root(x)!=root(y))
		{
			mincost+=cost;
			union1(x,y);
		}
	}
	return mincost;
}
int main()
{
	ll x,y;
	ll weight,cost,mincost;
	init();
	cin>>nodes>>edges;
	for(ll i=0;i<edges;i++)
	{
		cin>>x>>y>>weight;
		p[i]=make_pair(weight,make_pair(x,y));
	}
	sort(p,p+edges);
	mincost=kruskal(p);
	cout<<mincost<<"\n";
	return 0;
}
	

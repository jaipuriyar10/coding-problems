#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll dx[]={1,0,0,-1};
	ll dy[]={0,1,-1,0};
		
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,k,x,y;
		cin>>n>>m>>k;
		vector<pair<ll,ll>> v1;
		map<pair<ll,ll>,ll> ma;
		for(ll i=0;i<k;i++)
		{
			cin>>x>>y;
			--x;--y;
			v1.push_back({x,y});
			ma[{x,y}]=-1;
		}
		ll sum=0;
		ll cnt;
		for(auto it=v1.begin();it!=v1.end();it++)
		{
			x=it->first;
			y=it->second;
			cnt=4;
			for(ll i=0;i<4;i++)
			{
				ll u=x+dx[i];
				ll v=y+dy[i];
				if(u>=0 and u<n and v>=0 and v<m and ma[{u,v}]==-1)
				cnt--;
			}
			sum+=cnt;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
			

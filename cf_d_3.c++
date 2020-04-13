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
		unordered_map<ll,ll> ma;
		vector<pair<ll,ll>> vp;
		for(ll i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			ma[x]++;
		}
		for(auto it=ma.begin();it!=ma.end();it++)
		{
			vp.push_back({it->second,it->first});
		}
		sort(vp.begin(),vp.end());
		ll x=vp[vp.size()-1].first;
		ll y=vp.size()-1;
		if(y==0 and x==1)
		{cout<<0<<"\n";continue;}
		else
		{
			if(x>=y)
			{
				ll diff=(x-y);
				if(diff>=2)
				cout<<(y+1)<<"\n";
				else
				cout<<y<<"\n";
			}
			else if(x<y)
			{
				cout<<x<<"\n";
			}
		}
	}
	return 0;
}

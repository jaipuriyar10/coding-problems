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
		string str;
		cin>>str;
		map<pair<ll,ll>,ll> ma;
		pair<ll,ll> x={0,0};
		ma[x]=0;;
		ll l=-1;
		ll r=n;
		for(ll i=0;i<str.length();i++)
		{
			if(str[i]=='L')--x.first;
			if(str[i]=='R')++x.first;
			if(str[i]=='U')++x.second;
			if(str[i]=='D')--x.second;
			if(ma.count(x))
			{
				if(i-ma[x]+1<r-l+1)
				{
					l=ma[x];
					r=i;
				}
			}
			ma[x]=i+1;
		}
		if(l!=-1)
		cout<<(l+1)<<" "<<(r+1)<<"\n";
		else
		cout<<-1<<"\n";
	}
	return 0;
}

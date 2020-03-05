#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m,p;
	cin>>n>>m>>p;
	vector<ll> v1(n),v2(m);
	for(ll i=0;i<n;i++)
	cin>>v1[i];
	ll x;
	for(ll i=0;i<n;i++)
	{if(v1[i]%p)
		{x=i;break;}
	}
	for(ll i=0;i<m;i++)
	cin>>v2[i];
	ll y;
	for(ll i=0;i<m;i++)
	{
		if(v2[i]%p)
		{
			y=i;
			break;
		}
	}
	cout<<(x+y)<<"\n";
	return 0;
}
	

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
		string str;
		cin>>n>>m>>str;
		vector<ll> v1(n);
		for(ll i=0;i<m;i++)
		{
			ll x;
			cin>>x;
			++v1[x-1];
		}
		for(ll i=n-1;i>0;i--)
		{
			v1[i-1]+=v1[i];
		}
		vector<ll> v2(26);
		for(ll i=0;i<n;i++)
		{v2[str[i]-'a']+=v1[i];
		++v2[str[i]-'a'];
		}
		for(ll i=0;i<26;i++)
		cout<<v2[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
		
		

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,a,b,k;
	cin>>n>>a>>b>>k;
	vector<ll> v1(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v1[i];
		v1[i]=(v1[i]-1)%(a+b)/a;
	}
	sort(v1.begin(),v1.end());
	ll cnt=0;
	for(ll i=0;i<v1.size();i++)
	{
		k-=v1[i];
		if(k>=0)
		cnt++;
	}
	cout<<cnt<<"\n";
	
	return 0;
}

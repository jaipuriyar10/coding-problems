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
		ll arr[n+1];
		for(ll i=1;i<=n;i++)
		cin>>arr[i];
		arr[0]=0;
		ll id=0;
		for(ll i=1;i<=n;i++)
		{
			if(arr[i]>arr[id])
			id=i;
			m-=arr[i];
			if(m<0)
			break;
		}
		if(m>=0)
		cout<<0<<"\n";
		else
		cout<<id<<"\n";
	}
	return 0;
}

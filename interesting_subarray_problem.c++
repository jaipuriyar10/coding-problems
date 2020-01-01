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
		ll arr[n];
		for(ll i=0;i<n;i++)
		cin>>arr[i];
		for(ll i=0;i<n-1;i++)
		{
			if(arr[i+1]-arr[i]>=2)
			{cout<<"YES"<<"\n";cout<<(i+1)<<" "<<(i+2)<<"\n";goto end;}
			else if(arr[i]-arr[i+1]>=2)
			{cout<<"YES"<<"\n";cout<<(i+1)<<" "<<(i+2)<<"\n";goto end;}
		}
		cout<<"NO"<<"\n";
		end:continue;
	}
	return 0;
}

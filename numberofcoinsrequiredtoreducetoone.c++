#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	ll sum=0;
	unordered_map<ll,ll> ma;
	for(ll i=0;i<n;i++)
	{
		if((arr[i]!=1  || arr[i]!=-1)and arr[i]!=0)
		{if(arr[i]>0)sum+=(arr[i]-1),arr[i]=1,ma[arr[i]]++;
		else if(arr[i]<0)
		{sum+=(-1-arr[i]),arr[i]=-1;ma[arr[i]]++;}}
		else if(arr[i]==0)
		ma[0]++;
	}
	if(ma[0]==0)
	{
		if(ma[-1]%2==0)
		cout<<sum<<"\n";
		else if(ma[-1])
		{
			cout<<(sum+2)<<"\n";
		}
	}
	else
	{
		if(ma[0])
		cout<<(sum+ma[0])<<"\n";
		else
		cout<<sum<<"\n";
	}
	return 0;
}

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
	map<ll,ll> ma;
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		if((arr[i]!=1||arr[i]!=1)and arr[i]!=0)
		{
			if(arr[i]<0)
			{
			sum+=(-1-arr[i]);
			arr[i]=-1;
			ma[-1]++;
			}
			else
			{
				sum+=arr[i]-1;
				arr[i]=1;
				ma[1]++;
			}
		}
		else if(arr[i]==0)
		ma[0]++;
	}
	if(ma[0]==0)
	{
		if(ma[-1]%2==0)
		cout<<(sum)<<"\n";
		else
		cout<<(sum+2)<<"\n";
	}
	else
	{
		cout<<(sum+ma[0])<<"\n";
	}
	return 0;
}	
			

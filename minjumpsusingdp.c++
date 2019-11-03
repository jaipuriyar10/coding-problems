#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10000001];
ll minm(ll arr[],ll n,ll c)
{
	if(dp[c]!=-1)
	return dp[c];
	if(arr[c]==0)
	return (dp[c]=1e7);
	if(c>=n-1)
	return dp[c]=0;
	ll mn=1e7;
	for(ll i=1;i<=arr[c];i++)
	mn=min(mn,1+minm(arr,n,c+1));
	return dp[c]=mn;
}
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
		memset(dp,-1,sizeof(dp));
		ll x=minm(arr,n,0);
		if(x==1e7)
		cout<<-1<<"\n";
		else
		cout<<x<<"\n";
	}
	return 0;
}

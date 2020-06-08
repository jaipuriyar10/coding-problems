#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100005];
ll solve(ll arr[],ll n,ll &ans)
{
	if(n==1)
	return 1;
	ll res,msof=1;
	if(dp[n]!=-1)
	return dp[n];
	for(ll i=1;i<n;i++)
	{
		res=solve(arr,i,ans);
		if(arr[i-1]<arr[n-1] and res+1>msof)
		msof=res+1;
	}
	if(ans<msof)
	ans=msof;
	return dp[n]=msof;
}
int main()
{
	
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	memset(dp,-1,sizeof(dp));
	ll ans=1;
	solve(arr,n,ans);
	cout<<ans<<"\n";
	return 0;
}

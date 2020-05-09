#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dp[1003][1003];
bool solve(ll wt[],ll sum,ll n)
{
	if(sum==0)
	return (dp[n][sum]=true);
	if(dp[n][sum]!=false)
	return dp[n][sum];
	if(n==0 and sum!=0)
	return dp[n][sum]=false;
	if(wt[n-1]>sum)
	return (dp[n][sum]=solve(wt,sum,n-1));
	else
	return (dp[n][sum]=solve(wt,sum-wt[n-1],n-1)||solve(wt,sum,n-1));
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll wt[n];
		for(ll i=0;i<n;i++)
		cin>>wt[i];
		ll sum;
		cin>>sum;
		memset(dp,false,sizeof(dp));
		bool res=solve(wt,sum,n);
		cout<<res<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1003][1003];
ll solve(ll wt[],ll val[],ll n,ll cap)
{
	if(n==0||cap==0)
	return (dp[n][cap]=0);
	if(dp[n][cap]!=-1)
	return dp[n][cap];
	if(wt[n-1]>cap)
	return (dp[n][cap]=solve(wt,val,n-1,cap));
	else
	return (dp[n][cap]=max(val[n-1]+solve(wt,val,n-1,cap-wt[n-1]),solve(wt,val,n-1,cap)));
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
		ll val[n];
		for(ll i=0;i<n;i++)
		cin>>wt[i];
		for(ll i=0;i<n;i++)
		cin>>val[i];
		ll cap;
		cin>>cap;
		dp[0][0]=0;
		memset(dp,-1,sizeof(dp));
		ll res=solve(wt,val,n,cap);
		cout<<res<<"\n";
	}
	return 0;
}

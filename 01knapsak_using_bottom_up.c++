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
		ll wt[n];
		ll val[n];
		for(ll i=0;i<n;i++)
		cin>>wt[i];
		for(ll i=0;i<n;i++)
		cin>>val[i];
		ll cap;
		cin>>cap;
		ll dp[n+1][cap+1];
		for(ll i=0;i<=n;i++)
		dp[i][0]=0;
		for(ll j=0;j<=cap;j++)
		dp[0][j]=0;
		for(ll i=1;i<=n;i++)
		for(ll j=1;j<=cap;j++)
		{
			if(wt[i-1]>j)
			dp[i][j]=dp[i-1][j];
			else
			dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
		}
		cout<<dp[n][cap]<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,k;
	cin>>n>>k;
	ll dp[n+1][k+1];
	dp[0][0]=0;
	for(ll i=1;i<=n;i++)
	dp[0][i]=0;
	for(ll i=1;i<=k;i++)
	{
		dp[0][i]=0;
		dp[1][i]=i;
	}
	for(ll i=2;i<=n;i++)
	{
		for(ll j=2;j<=k;j++)
		{
			dp[i][j]=INT_MAX;
			ll subres;
			for(ll k=1;k<=j;k++)
			{
				subres=max(dp[i-1][k-1],dp[i][j-k]);
				dp[i][j]=min(dp[i][j],1+subres);
		
			}
		}
	}
	cout<<dp[n][k]<<"\n";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m;
	cin>>n>>m;
	ll wt[n],val[n];
	for(ll i=0;i<n;i++)
	cin>>wt[i];
	for(ll j=0;j<n;j++)
	cin>>val[j];
	ll dp[n+1][m+1];
	for(ll i=0;i<=n;i++)
	for(ll j=0;j<=m;j++)
	{
		if(i==0||j==0)
		dp[i][j]=0;
		else
		{
			if(j>=wt[i-1])
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	for(ll i=0;i<=n;i++)
	{{for(ll j=0;j<=m;j++)
	cout<<dp[i][j]<<" ";}cout<<"\n";}
	cout<<dp[n][m]<<"\n";
	return 0;
}
			

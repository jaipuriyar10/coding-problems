#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll k;
	cin>>k;
	ll arr[k];
	for(ll i=0;i<k;i++)
	cin>>arr[i];
	ll dp[k+1][n+1];
	for(ll i=0;i<=k;i++)
	{
		for(ll j=0;j<=n;j++)
		{
			if(i==0||j==0)
			{dp[i][j]=0;continue;}
			if(j<i)
			dp[i][j]=dp[i-1][j];
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-i]+arr[i-1]);
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<dp[k][n]<<"\n";
	return 0;
}

			

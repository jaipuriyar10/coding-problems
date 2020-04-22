#include<bits/stdc++.h>
using namespace std;
typedef double ll;
int main()
{
	int n;
	cin>>n;
	ll p[n];
	for(int i=0;i<n;i++)
	cin>>p[i];
	ll dp[n+1][n+1];
	dp[1][1]=p[0];
	dp[1][0]=1-p[0];
	for(int i=2;i<=n;i++)
	dp[i][0]=dp[i-1][0]*(1-p[i-1]);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		dp[i][j]=dp[i-1][j-1]*p[i-1]+dp[i-1][j]*(1-p[i-1]);
	}
	ll sum=0;
	for(int i=n/2+n%2;i<=n;i++)
	sum+=dp[n][i];
	cout<<setprecision(10)<<sum;
	return 0;
}

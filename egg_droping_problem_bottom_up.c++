#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cout<<"Enter number of test cases: ";
	cin>>t;
	while(t--)
	{
		int n,k;
		cout<<"Enter number of eggs and number of floors: ";
		cin>>n>>k;
		int dp[n+1][k+1];
		memset(dp,0,sizeof(dp));
		dp[0][0]=0;   //if we have 0 eggs
		dp[0][1]=0;
		for(int i=1;i<=n;i++)
		{dp[i][0]=0;dp[i][1]=1;}  // when we have 0 or 1 floor then we need 0 and one attempts in worst case respectively
		for(int i=1;i<=k;i++)
		{dp[0][i]=0,dp[1][i]=i;}  //base cases
		
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=k;j++)
			{
				dp[i][j]=INT_MAX;
				for(int x=1;x<=j;x++)
				{
					int subres=max(dp[i-1][x-1],dp[i][j-x]); //max for worst case
					dp[i][j]=min(dp[i][j],1+subres);         // one added for current attempts.
				}
			}
		}
		cout<<"Minimum number of attempts: ";
		cout<<dp[n][k]<<"\n";
	}
	return 0;
}
	

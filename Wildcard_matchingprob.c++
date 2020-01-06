#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string str1,str2;
	cin>>str1>>str2;
	ll n=str1.length();
	ll m=str2.length();
	bool dp[n+1][m+1];
	memset(dp,false,sizeof(dp));
	
	dp[0][0]=true;
	for(ll j=1;j<=m;j++)
	if(str2[j-1]=='*')
	dp[0][j]=dp[0][j-1];
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=m;j++)
	{
		if(str2[j-1]=='*')
		dp[i][j]=dp[i-1][j]||dp[i][j-1];
		else if((str2[j-1]==str1[i-1])||str2[j-1]=='?')
		dp[i][j]=dp[i-1][j-1];
		else
		dp[i][j]=false;
	}
	cout<<dp[n][m];
	return 0;
}

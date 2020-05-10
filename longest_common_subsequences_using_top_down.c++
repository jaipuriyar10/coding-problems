#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1003][1003];
ll solve(string str1,string str2,ll n,ll m)
{
	if(n==0||m==0)
	return dp[n][m]=0;
	else if(dp[n][m]!=-1)
	return dp[n][m];
	else if(str1[n-1]==str2[m-1])
	return dp[n][m]=1+solve(str1,str2,n-1,m-1);
	else
	return dp[n][m]=max(solve(str1,str2,n-1,m),solve(str1,str2,n,m-1));
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		memset(dp,-1,sizeof(dp));
		ll n=str1.length();
		ll m=str2.length();
		cout<<solve(str1,str2,n,m);
	}
	return 0;
}

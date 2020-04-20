

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string str1,str2;
	cin>>str1>>str2;
	ll n=str1.length();
	ll m=str2.length();
	ll dp[n+1][m+1];
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=m;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			else
			{
			if(str1[i-1]==str2[j-1])
			dp[i][j]=dp[i-1][j-1]+1;
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	}
	ll len;
	len=dp[n][m];
	string str;
	str.resize(len);
	ll i=str1.length();
	ll j=str2.length();
	while(i>0 and j>0)
	{
		if(str1[i-1]==str2[j-1])
		{
			str[len-1]=str1[i-1];
			len--;
			i--;
			j--;
		}
		else
		{
			if(dp[i-1][j]>dp[i][j-1])i--;
			else
			j--;
		}
	}
	cout<<str<<"\n";
	return 0;
}

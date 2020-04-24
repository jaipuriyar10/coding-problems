#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string str;
	cin>>str;
	ll n=str.length();
	ll dp[n][n];
	memset(dp,0,sizeof(dp));
	for(ll i=0;i<n;i++)
	dp[i][i]=1;
	ll st=-1;
	ll ans=1;
	for(ll i=0;i<n-1;i++)
	{
		if(str[i]==str[i+1])
		{
			dp[i][i+1]=1;
			st=i;
			ans=2;
		}
	}
	for(ll i=3;i<=n;i++)
	{
		for(ll j=0;j<n-i+1;j++)
		{
			int k=i+j-1;
			if(dp[j+1][k-1] and str[j]==str[k])
			{
				dp[j][k]=1;
				st=j;
				ans=max(ans,i);
			}
		}
	}
	cout<<st<<" "<<ans<<"\n";
	if(st==-1 and ans==1)
	cout<<str[0]<<"\n";
	else
	cout<<str.substr(st,ans)<<"\n";
	//cout<<ans<<"\n";
	return 0;
}

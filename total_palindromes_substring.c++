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
	string str;
	cin>>str;
	//ll n=str.length();
	ll dp[n][n];
	memset(dp,0,sizeof(dp));
	bool p[n][n];
	memset(p,false,sizeof(p));
	for(ll i=0;i<n;i++)
	{	p[i][i]=true;
	}
	for(ll i=0;i<n-1;i++)
	{
		if(str[i]==str[i+1])
		{
			p[i][i+1]=true;
			dp[i][i+1]=1;
		}
	}
	for(ll gap=2;gap<n;gap++)
	{
		for(ll i=0;i<n-gap;i++)
		{
			ll j=gap+i;
			if(str[i]==str[j] and p[i+1][j-1])
			p[i][j]=true;
			if(p[i][j]==true)
			dp[i][j]=dp[i][j-1]+dp[i+1][j]+1-dp[i+1][j-1];
			else
			dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
		}
	}
	cout<<dp[0][n-1]<<"\n";
}
return 0;
}


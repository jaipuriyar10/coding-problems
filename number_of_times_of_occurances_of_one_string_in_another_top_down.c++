#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1004][1004];
ll count(string str1,string str2,ll n,ll m)
{
	if((n==0 and m==0)||(m==0))
	dp[n][m]=1;
	else if(n==0)
	dp[n][m]=0;
	if(dp[n][m]!=-1)
	return dp[n][m];
	if(str1[n-1]==str2[m-1])
	dp[n][m]=(count(str1,str2,n-1,m-1)+count(str1,str2,n-1,m));
	else
	dp[n][m]=count(str1,str2,n-1,m);
	return dp[n][m];
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
	ll n,m;
	cin>>n>>m;
	string str1,str2;
	cin>>str1>>str2;
	memset(dp,-1,sizeof(dp));
	for(ll i=0;i<=m;i++)
	dp[0][i]=0;
	dp[0][0]=1;
	for(ll i=0;i<=n;i++)
	dp[i][0]=1;
	ll res=count(str1,str2,n,m);
	cout<<res<<"\n";
    }
	return 0;
}
	

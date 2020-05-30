#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[11];
ll dp[11][110][2];
ll solve(ll pos,ll sum,ll n,bool flag)
{
	if(pos>n)
	return sum;
	if(dp[pos][sum][flag]!=-1)
	return dp[pos][sum][flag];
	ll lim=9;
	if(!flag)
	lim=arr[pos];
	ll res=0;
	for(ll i=0;i<=lim;i++)
	{
		if(flag==true||i<lim)
		res+=solve(pos+1,sum+i,n,true);
		else
		res+=solve(pos+1,sum+i,n,false);
	}
	return dp[pos][sum][flag]=res;
}
ll digsum(string x)
{
	ll res=0;
	for(ll i=0;i<x.length();i++)
	res+=(x[i]-'0');
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a,b;
	while(1)
	{
		cin>>a>>b;
		if(a=="-1" and b=="-1")
		break;
		memset(dp,-1,sizeof(dp));
		
		for(ll i=0;i<a.size();i++)
		{
			arr[i+1]=a[i]-'0';
		}
		ll l=solve(1,0,a.size(),false);
		memset(dp,-1,sizeof(dp));
		for(ll i=0;i<b.size();i++)
		{
			arr[i+1]=b[i]-'0';
		}
		ll r=solve(1,0,b.size(),false);
		cout<<(r-l+digsum(a))<<"\n";
	}
	return 0;
}

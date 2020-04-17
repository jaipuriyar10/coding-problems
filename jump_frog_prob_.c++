#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,k;
  cin>>n>>k;
  ll dp[n];
  ll h[n];
  for(ll i=0;i<n;i++)
    cin>>h[i];
  //memset(dp,1e9,sizeof(dp));
  for(ll i=0;i<n;i++)
  dp[i]=1000000007;
  dp[0]=0;
  dp[1]=abs(h[0]-h[1]);
  //int cnt=k;
  for(ll i=2;i<n;i++)
  {
    for(ll j=1;j<=k;j++)
    {
		if(j<=i)
		dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
		
	}
  }
  //for(ll i=0;i<n;i++)
  //cout<<dp[i]<<" ";
  cout<<dp[n-1];
  return 0;
}

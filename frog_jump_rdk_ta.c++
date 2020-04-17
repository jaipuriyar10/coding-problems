#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n;
  cin>>n;
  ll dp[n];
  ll h[n];
  for(ll i=0;i<n;i++)
    cin>>h[i];
  dp[0]=0;
  dp[1]=abs(h[0]-h[1]);
     for(ll i=2;i<n;i++)
     {
       dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
	 }
  cout<<dp[n-1];
 return 0;
}

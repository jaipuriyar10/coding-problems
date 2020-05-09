#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll wt[n];
        for(ll i=0;i<n;i++)
        cin>>wt[i];
        ll sum;
        cin>>sum;
        ll dp[n+1][sum+1];
        for(ll i=0;i<=n;i++)
        dp[i][0]=1;
        for(ll i=0;i<=sum;i++)
        dp[0][i]=0;
        dp[0][0]=1;
        for(ll i=1;i<=n;i++)
        for(ll j=1;j<=sum;j++)
        {
            if(wt[i-1]>j)
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-wt[i-1]]%mod)%mod;
        }
        cout<<dp[n][sum]<<"\n";
    }
    return 0;
}

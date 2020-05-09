#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1003][1003];
#define mod 1000000007
ll solve(ll wt[],ll n,ll sum)
{
    if(sum==0)
    return (dp[n][sum]=1);
    if(dp[n][sum]!=-1)
    return dp[n][sum];
    if(n==0 and sum!=0)
    return (dp[n][sum]=0);
    if(wt[n-1]>sum)
    return (dp[n][sum]=solve(wt,n-1,sum));
    else
    return (dp[n][sum]=((solve(wt,n-1,sum)%mod)+(solve(wt,n-1,sum-wt[n-1])%mod))%mod);
}
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
        memset(dp,-1,sizeof(dp));
        ll res=solve(wt,n,sum);
        cout<<res<<"\n";
    }
    return 0;
}

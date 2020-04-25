#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1004][1004];
ll solve(ll n,ll k)
{
    if(k==0||k==1)
    return k;
    if(n<=0)
    return 0;
    if(n==1)
        return k;
    if(dp[n][k]!=-1)
    return dp[n][k];
    ll ans=INT_MAX;
    for(ll i=1;i<=k;i++)
    {
        ll subres=max(solve(n-1,i-1),solve(n,k-i));
        ans=min(ans,subres);
    }
    dp[n][k]=1+ans;
    return dp[n][k];
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        for(ll i=0;i<=n;i++)
        for(ll j=0;j<=k;j++)
        dp[i][j]=-1;
        dp[0][0]=0;
        for(ll i=1;i<=k;i++)
        {dp[0][i]=0;dp[1][i]=i;}
        ll res=solve(n,k);
        cout<<dp[n][k]<<"\n";
    }
    return 0;
    
}

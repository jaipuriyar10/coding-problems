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
        ll wt[n];
        for(ll i=0;i<n;i++)
        cin>>wt[i];
        ll sum=accumulate(wt,wt+n,0);
        bool dp[n+1][sum+1];
        for(ll i=0;i<=sum;i++)
        dp[0][i]=false;
        for(ll i=0;i<=n;i++)
        dp[i][0]=true;
        for(ll i=1;i<=n;i++)
        for(ll j=1;j<=sum;j++)
        {
            if(wt[i-1]>j)
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j-wt[i-1]]||dp[i-1][j];
        }
        ll ans=INT_MAX;
        for(ll i=sum/2;i>=0;i--)
        {
            if(dp[n][i])
            ans=min(ans,sum-2*i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

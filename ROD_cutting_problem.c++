problem:- https://practice.geeksforgeeks.org/problems/cutted-segments/0
using namespace std;
typedef long long ll;
ll solve(ll n,ll x,ll y,ll z,ll dp[])
{
    if(n==0)
    return 0;
    else if(n<0)
    return INT_MIN;
    if(dp[n]!=-1)
    return dp[n];
    else if(dp[n]==-1)
    {
        ll res=INT_MIN;
        if((n-x)>=0)
        dp[n]=max(res,1+solve(n-x,x,y,z,dp));
        if((n-y)>=0)
        dp[n]=max(dp[n],1+solve(n-y,x,y,z,dp));
        if((n-z)>=0)
        dp[n]=max(dp[n],1+solve(n-z,x,y,z,dp));
        if(dp[n]==-1)
        return INT_MIN;
    }
    return dp[n];
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll x,y,z;
        cin>>x>>y>>z;
        ll res=0;
        ll dp[n+1];
        memset(dp,-1,sizeof(dp));
        res=solve(n,x,y,z,dp);
        cout<<res<<"\n";
    }
    return 0;
}

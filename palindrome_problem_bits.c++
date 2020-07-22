#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define maxxm 1000005
bool solve1(ll n)
{
    string str="";
    while(n>0)
    {
        str+=('0'+n%2);
        n/=2;
    }
    string str2=str;
    reverse(str2.begin(),str2.end());
    if(str2==str)
    return true;
    else
    return false;
}
bool solve2(ll n)
{
    string str="";
    while(n>0)
    {
        str+=('0'+n%10);
        n/=10;
    }
    string str2=str;
    reverse(str2.begin(),str2.end());
    if(str2==str)
    return true;
    else
    return false;
}


int main()
{
    ll t;
    cin>>t;
    ll dp[maxxm];
    dp[0]=0;
    dp[1]=1;
    for(ll i=2;i<maxxm;i++)
    {
        bool f1=solve1(i);
        bool f2=solve2(i);
        dp[i]=dp[i-1];
        if(f1 and f2)
        dp[i]+=1;
    }

    while(t--)
    {
        ll n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
}

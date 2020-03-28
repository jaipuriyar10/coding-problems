#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sqsum(ll n)
{
    ll sum=0;
    while(n>0)
    {
        sum+=(n%10)*(n%10);
        n/=10;
    }
    return sum;
}
bool valid(ll n)
{
    ll slow,fast;
    slow=n;
    fast=n;
    do
    {
        slow=sqsum(slow);
        fast=sqsum(sqsum(fast));
    }
    while(slow!=fast);
    if(slow==1)
    return true;
    else
    return false;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        while(1)
        {
            n++;
            if(valid(n))
            {cout<<n<<"\n";goto end;}
            
        }
        
        end:;
        
    }
    return 0;
}

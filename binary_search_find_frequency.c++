#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        ll arr[n];
        for(ll i=0;i<n;i++)
        cin>>arr[i];
        ll lo=0;
        ll hi=n-1;
        int res1=-1,res2=-1;
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            if(arr[mid]==x)
            {
                res1=mid;
                hi=mid-1;
                continue;
            }
            if(arr[mid]>x)
            {
                hi=mid-1;
            }
            else
            lo=mid+1;
        }
        lo=0;
        hi=n-1;
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            if(arr[mid]==x)
            {
                res2=mid;
                lo=mid+1;
                continue;
            }
            if(arr[mid]>x)
            {
                hi=mid-1;
            }
            else
            lo=mid+1;
        }
        if(res1!=-1 and res2!=-1)
        cout<<(res2-res1+1)<<"\n";
        else
        cout<<-1<<"\n";
    }
    return 0;
}

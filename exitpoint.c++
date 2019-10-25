
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll arr[n][m];
        for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
        cin>>arr[i][j];
        ll i,j,pi,pj;
        i=0;
        j=0;
        pi=0;
        pj=0;
        ll d=0;
        while(i>=0 and i<n and j>=0 and j<m)
        {
            pi=i;
            pj=j;
            if(arr[i][j]==1)
            {
                d=(d+1)%4;
                arr[i][j]=0;
            }
            if(d==0)
            j++;
            if(d==1)
            i++;
            if(d==2)
            j--;
            if(d==3)
            i--;
        }
        cout<<pi<<" "<<pj<<"\n";
    }
    return 0;
}

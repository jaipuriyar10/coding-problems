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
        stack<int> v1[n+1];
        queue<int> v2[n+1];
        for(ll i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;
            v1[x].push(y);
        }
        for(ll i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;
            v2[x].push(y);
        }
        bool flag;
        for(int i=1;i<=n;i++)
        {
            stack<int>&s=v1[i];
            queue<int>&q=v2[i];
        
         flag=true;
        while(!s.empty() and !q.empty())
        {
            if(s.top()!=q.front())
            {
                flag=false;
                break;
            }
            s.pop();
            q.pop();
        }
        if(flag==false)
        break;
        }
        if(flag==true)
        cout<<1<<"\n";
        else
        cout<<0<<"\n";
    }
    return 0;
}

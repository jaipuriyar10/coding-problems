#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        unordered_map<char,ll> ma;
        string str;
        cin>>str;
        ll k;
        cin>>k;
        for(ll i=0;i<str.length();i++)
        {ma[str[i]]++;}
        priority_queue<ll>q;
        for(auto it=ma.begin();it!=ma.end();it++)
        {
            q.push(it->second);
        }
        ll sum=0;
        while(k--)
        {
            ll x=q.top();
            q.pop();
            x--;
            q.push(x);
        }
        while(!q.empty())
        {
            sum+=(q.top()*q.top());
            q.pop();
        }
        cout<<sum<<"\n";
    }
    return 0;
}

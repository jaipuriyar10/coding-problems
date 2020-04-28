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
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
        cin>>arr[i];
        vector<ll> v1,v2;
        stack<pair<int,int>> st,st1;
        st.push({INT_MIN,-1});
        for(int i=0;i<n;i++)
        {
            bool flag=false;
            while(!st.empty())
            {
                if(st.top().first<arr[i])
                {
                    v1.push_back(st.top().second);
                    st.push({arr[i],i});
                    flag=true;
                    break;
                }
                else
                st.pop();
            }
        }
        //st.clear();
        st1.push({INT_MIN,n});
        for(int i=n-1;i>=0;i--)
        {
            bool flag=false;
            while(!st1.empty())
            {
                if(st1.top().first<arr[i])
                {
                    v2.push_back(st1.top().second);
                    st1.push({arr[i],i});
                    flag=true;
                    break;
                }
                else
                st1.pop();
            }
            
        }
        reverse(v2.begin(),v2.end());
        ll ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(v2[i]-v1[i]-1)*arr[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

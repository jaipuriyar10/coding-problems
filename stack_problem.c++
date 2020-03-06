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
		vector<ll> v1(n),v2(n);
		for(ll i=0;i<n;i++)
		cin>>v1[i];
		stack<ll> st;
		st.push(0);
		for(ll i=1;i<n;i++)
		{
			ll cur=v1[i];
			while(st.empty()==false and v1[st.top()]<cur)
			{
				v2[st.top()]=cur;
				st.pop();
			}
			st.push(i);
		}
		while(st.empty()==false)
		{
			v2[st.top()]=-1;
			st.pop();
		}
		for(ll i=0;i<n;i++)
		cout<<v2[i]<<" ";
		cout<<"\n";
	}
	return 0;
}

		

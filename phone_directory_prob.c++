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
		vector<string> v1(n);
		for(ll i=0;i<n;i++)
		cin>>v1[i];
		string str;
		cin>>str;
		for(ll i=1;i<=str.length();i++)
		{
			ll cnt=0;
			set<string> st;
			string prev=str.substr(0,i);
			for(ll k=0;k<n;k++)
			{
				string cur=v1[k].substr(0,i);
				if(cur==prev)
				{st.insert(v1[k]);cnt++;}
			}
			if(cnt==0)
			cout<<0<<"\n";
			else
			{	for(auto it=st.begin();it!=st.end();it++)
				cout<<*it<<" ";
				cout<<"\n";
			}
		}
	}
	return 0;
}

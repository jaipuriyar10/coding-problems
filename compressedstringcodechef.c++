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
		string str,str2;
		cin>>str;
		vector<pair<char,ll>> vp;
		ll l=1;
		char c=str[0];
		for(ll i=1;i<str.length();i++)
		{
			if(c==str[i])l++;
			else
			{
				vp.push_back({c,l});
				c=str[i];
				l=1;
			}
		}
		vp.push_back({str[str.length()-1],l});
		str2="";
		for(auto it=vp.begin();it!=vp.end();it++)
		{
			str2+=it->first;
			str2+=to_string(it->second);
		}
		if(str2.length()>=str.length())
		cout<<"NO"<<"\n";
		else
		cout<<"YES"<<"\n";
	}
	return 0;
}
		

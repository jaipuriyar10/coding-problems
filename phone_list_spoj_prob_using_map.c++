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
		vector<string> v1;
		string str;
		for(ll i=0;i<n;i++)
		{
			cin>>str;
			v1.push_back(str);
		}
		sort(v1.begin(),v1.end());
		string prev="abcdef";
		for(ll i=0;i<n;i++)
		{
			ll len=prev.length();
			string cur=v1.at(i).substr(0,len);
			if(cur==prev)
			{
				cout<<"NO"<<"\n";
				goto end;
			}
			prev=v1.at(i);
		}
		cout<<"YES"<<"\n";
		end:
		continue;
	}
	return 0;
}
			

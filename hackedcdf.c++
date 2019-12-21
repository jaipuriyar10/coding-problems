#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	map<string,string> ma;
	set<string> st;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		ma[str1]=str2;
		st.insert(str2);
	}
	vector<pair<string,string>> vp;
	for(auto it=ma.begin();it!=ma.end();it++)
	{
		if(st.count(it->first))
		continue;
		string str=it->first;
		while(ma.count(str))
		{
			str=ma[str];
		}
		vp.push_back({it->first,str});
	}
	cout<<vp.size()<<"\n";
	for(auto it=vp.begin();it!=vp.end();it++)
	cout<<it->first<<" "<<it->second<<"\n";
	return 0;
}

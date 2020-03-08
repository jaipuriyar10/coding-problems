#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,x;
		cin>>n;
		vector<pair<ll,ll>>v1;
		for(ll i=0;i<n;i++)
		{
			cin>>x;
			v1.push_back({x,i+1});
		}
		bool flag=false;
		for(ll i=0;i<(1<<n);i++)
		{
			vector<pair<ll,ll>> v2;
			for(ll j=0;j<n;j++)
			{
				if(i&(1<<j))
				v2.push_back({v1[j].first,v1[j].second});
			}
			ll sum=0;
			for(auto it=v2.begin();it!=v2.end();it++)
			sum+=it->first;
			if(sum%2==0 and sum!=0)
			{
				flag=true;
				cout<<v2.size()<<"\n";
				for(auto it=v2.begin();it!=v2.end();it++)
				cout<<it->second<<" ";
				cout<<"\n";
				goto end;
			}
		}
		if(flag==false)
		cout<<-1<<"\n";
		end:
		continue;
	}
	return 0;
}
		

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200005];
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		priority_queue<pair<ll,pair<ll,ll>>>pq;
		pq.push({n,{-1,-n}});
		ll cnt=1;
		while(!pq.empty())
		{
			pair<ll,pair<ll,ll>>p=pq.top();
			pq.pop();
			ll l=p.second.first*-1;
			ll r=p.second.second*-1;
			ll mid=(l+r)/2;
			arr[mid]=cnt;
			cnt++;
			if(l==r)
			continue;
			else
			{
				if(mid-1>0 and mid-1>=l)
				{
					ll len=mid-l;
					pq.push({len,{(-1)*l,(-1)*(mid-1)}});
				}
				if(mid+1<=n and mid+1<=r)
				{
					ll len=r-(mid);
					pq.push({len,{(-1)*(mid+1),(-1)*r}});
				}
			}
		}
		for(ll i=1;i<=n;i++)
		cout<<arr[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
			
		

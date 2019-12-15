#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	ll arr[1000005];
	ll cnt[1000005];
	ll ind[1000005];
	while(t--)
	{
		ll n;
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		memset(ind,-1,sizeof(ind));
		
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			ind[arr[i]]=i;
		}
		ll ans=0;
		for(ll i=0;i<n;i++)
		{
			for(ll j=1;j<=sqrt(arr[i]);j++)
			{
				if(arr[i]%j==0)
				{
					if(arr[i]/j==j)
					{
						if(ind[j]>i)
						cnt[j]++;
						ans=max(ans,cnt[j]);
					}
					else
					{
						if(ind[j]>i)
						cnt[j]++;
						ans=max(ans,cnt[j]);
						ll m=arr[i]/j;
						if(ind[m]>i)
						cnt[m]++;
						ans=max(ans,cnt[m]);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
		
		

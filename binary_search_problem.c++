SPOJ:Aggreesive cow.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100001];
bool isvalid(ll arr[],ll n,ll maxm,ll k)
{
	ll cnt=0;
	ll prev=-INT_MAX;
	for(ll i=1;i<=n;i++)
	{
		if((arr[i]-prev)>=maxm)
		{
			prev=arr[i];
			cnt++;
		}
	}
	if(cnt>=k)
	return true;
	else
	return false;
}
void solve(ll arr[],ll n,ll k)
{
	ll l=0;
	ll r=arr[n]-arr[1];
	ll mid;
	ll ans=INT_MIN;
	while(l<=r)
	{
		mid=l+(r-l)/2;
		if(isvalid(arr,n,mid,k))
		ans=max(ans,mid),l=mid+1;
		else
		r=mid-1;
	}
	cout<<ans<<"\n";
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		for(ll i=1;i<=n;i++)
		cin>>arr[i];
		sort(arr+1,arr+1+n);
		solve(arr,n,k);
	}
	return 0;
}

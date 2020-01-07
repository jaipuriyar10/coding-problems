#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll _mergesort(ll arr[],ll temp[],ll l,ll r);
ll merge(ll arr[],ll temp[],ll l,ll m,ll r);

ll mergesort(ll arr[],ll size)
{
	ll temp[size];
	return _mergesort(arr,temp,0,size-1);
}
ll _mergesort(ll arr[],ll temp[],ll l,ll r)
{
	ll mid,inv_cnt=0;
	if(l<r)
	{
		mid=(l+r)/2;
		inv_cnt+=_mergesort(arr,temp,l,mid);
		inv_cnt+=_mergesort(arr,temp,mid+1,r);
		inv_cnt+=merge(arr,temp,l,mid+1,r);
	}
	return inv_cnt;
}
ll merge(ll arr[],ll temp[],ll l,ll mid,ll r)
{
	ll i,j,k;
	ll inv_cnt=0;
	i=l;
	j=mid;
	k=l;
	while((i<=mid-1)&&(j<=r))
	{
		if(arr[i]<=arr[j])
		temp[k++]=arr[i++];
		else
		{temp[k++]=arr[j++];
		inv_cnt+=(mid-i);}
	}
	while(i<=mid-1)
	temp[k++]=arr[i++];
	while(j<=r)
	temp[k++]=arr[j++];
	for(ll i=l;i<=r;i++)
	arr[i]=temp[i];
	return inv_cnt;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	cout<<mergesort(arr,n)<<"\n";
	}
	return 0;
}
	

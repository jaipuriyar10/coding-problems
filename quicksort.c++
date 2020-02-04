#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll partition(ll arr[],ll low,ll high)
{
	ll i=low-1;
	ll pivot=high;
	for(ll j=low;j<=high-1;j++)
	{
		if(arr[j]<arr[pivot])
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return (i+1);
}
void quicksort(ll arr[],ll low,ll high)
{
	if(low<high)
	{
		ll pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	quicksort(arr,0,n-1);
	for(ll i=0;i<n;i++)
	cout<<arr[i];
	return 0;
}

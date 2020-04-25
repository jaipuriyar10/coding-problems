#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll arr[],ll i,ll j)
{
	if(i>=j)
	return 0;
	ll temp;
	ll res=INT_MAX;
	for(ll k=i;k<j;k++)
	{
		temp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		res=min(res,temp);
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	ll res=solve(arr,1,n-1);
	cout<<res<<"\n";
	return 0;
}

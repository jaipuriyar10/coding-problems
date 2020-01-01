#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pos[100005];
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		memset(pos,0,sizeof(pos));
	ll n,m;
	cin>>n>>m;
	ll arr[n],brr[m];
	for(ll i=0;i<n;i++)
	{cin>>arr[i];pos[arr[i]]=(i);}
	ll lst=-1;
	for(ll i=0;i<m;i++)
	cin>>brr[i];
	ll res=m;
	for(ll i=0;i<m;i++)
	{
		if(pos[brr[i]]>lst)
		{res+=(2*(pos[brr[i]]-i));
		lst=pos[brr[i]];
		}
	}
	cout<<res<<"\n";}
	return 0;
}

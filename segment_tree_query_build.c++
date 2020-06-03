#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100005];
ll st[4*100005];
void build(ll si,ll ss,ll se)
{
	if(ss==se)
	{
		st[si]=arr[ss];
		return ;
	}
	ll mid=ss+(se-ss)/2;
	build(2*si,ss,mid);
	build(2*si+1,mid+1,se);
	st[si]=min(st[2*si],st[2*si+1]);
	return ;
}
ll query(ll si,ll ss,ll se,ll qs,ll qe)
{
	if(ss>qe|| se<qs)
	return INT_MAX;
	
	if(ss>=qs and se<=qe)
	return st[si];
	else
	{
		ll mid=ss+(se-ss)/2;
		return min(query(2*si,ss,mid,qs,qe),query(2*si+1,mid+1,se,qs,qe));
	}
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	cin>>arr[i];
	build(1,1,n);
	ll q;
	cin>>q;
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		x++;
		y++;
		cout<<query(1,1,n,x,y)<<"\n";
	}
	return 0;
}

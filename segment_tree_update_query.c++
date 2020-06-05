problem:https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/?layout=old


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100001];
pair<ll,ll> st[4*100001];
void build(ll si,ll ss, ll se)
{
	if(ss==se)
	{
		if(arr[ss]%2==0)
		st[si]={0,1};
		else
		st[si]={1,0};
		return ;
	}
	ll mid=ss+(se-ss)/2;
	build(2*si,ss,mid);
	build(2*si+1,mid+1,se);
	st[si].first=st[2*si].first+st[2*si+1].first;
	st[si].second=st[2*si].second+st[2*si+1].second;
	return ;
}
void update(ll si,ll ss,ll se,ll qi,ll val)
{
	if(ss==se)
	{
		arr[qi]=val;
		if(arr[qi]%2==0)
		st[si]={0,1};
		else
		st[si]={1,0};	
		return ;
	}
	ll mid=ss+(se-ss)/2;
	if(qi<=mid)
	update(2*si,ss,mid,qi,val);
	else
	update(2*si+1,mid+1,se,qi,val);
	st[si].first=st[2*si].first+st[2*si+1].first;
	st[si].second=st[2*si].second+st[2*si+1].second;
	return ;

}
ll query1(ll si,ll ss,ll se,ll qs,ll qe)
{
	if(ss>qe|| se<qs)
	return 0;
	if(ss>=qs and se<=qe)
	return st[si].first;
	ll mid=ss+(se-ss)/2;
	return query1(2*si,ss,mid,qs,qe)+query1(2*si+1,mid+1,se,qs,qe);
}
ll query2(ll si,ll ss,ll se,ll qs,ll qe)
{
	if(ss>qe|| se<qs)
	return 0;
	if(ss>=qs and se<=qe)
	return st[si].second;
	ll mid=ss+(se-ss)/2;
	return query2(2*si,ss,mid,qs,qe)+query2(2*si+1,mid+1,se,qs,qe);
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
		ll z,x,y;
		cin>>z>>x>>y;
		if(z==0)
		{
			if(arr[x]%2==y%2)
			continue;
			else
			update(1,1,n,x,y);
		}
		else if(z==2)
		{
			cout<<query1(1,1,n,x,y)<<"\n";
		}
		else if(z==1)
		{
			cout<<query2(1,1,n,x,y)<<"\n";
		}
	}
	return 0;
}

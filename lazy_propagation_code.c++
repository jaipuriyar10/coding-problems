problem url:https://www.spoj.com/problems/HORRIBLE/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100001];
ll st[4*100001];
ll lazy[4*100001];
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
	st[si]=st[2*si]+st[2*si+1];
	return ;
}
ll query(ll si,ll ss,ll se,ll qs,ll qe)
{
	if(lazy[si]!=0)
	{
		ll dx=lazy[si];
		lazy[si]=0;
		st[si]+=dx*(se-ss+1);
		if(ss!=se)
		{
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	if(ss>qe || se<qs)
	return 0;
	if(ss>=qs and se<=qe)
	return st[si];
	ll mid=ss+(se-ss)/2;
	return query(2*si,ss,mid,qs,qe)+query(2*si+1,mid+1,se,qs,qe);
}
void update(ll si,ll ss,ll se,ll qs,ll qe,ll val)
{
	if(lazy[si]!=0)
	{
		ll dx=lazy[si];
		st[si]+=dx*(se-ss+1);
		lazy[si]=0;
		if(ss!=se)
		{
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	if(ss>qe||se<qs)
	return ;
	if(ss>=qs and se<=qe)
	{
		ll dx=(se-ss+1)*val;
		st[si]+=dx;
		if(se!=ss)
		{
			lazy[2*si]+=val;
			lazy[2*si+1]+=val;
		}
		return ;
	}
	ll mid=ss+(se-ss)/2;
	update(2*si,ss,mid,qs,qe,val);
	update(2*si+1,mid+1,se,qs,qe,val);
	st[si]=st[2*si]+st[2*si+1];
	return ;
}
			
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,c;
		cin>>n>>c;
		for(ll i=1;i<=n;i++)
		arr[i]=0;
		build(1,1,n);
		ll x,y,val;
		while(c--)
		{
			ll z;
			cin>>z;
			if(z==0)
			{
				cin>>x>>y>>val;
				update(1,1,n,x,y,val);
			}
			if(z==1)
			{
				cin>>x>>y;
				cout<<query(1,1,n,x,y)<<"\n";
			}
		}
		for(ll i=1;i<=n;i++)
		arr[i]=0;
		memset(lazy,0,sizeof(lazy));
	}
	return 0;
}
				
		

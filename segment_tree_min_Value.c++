#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxm 100005
ll arr[maxm];
ll tree[4*maxm];
void build(ll node,ll st,ll en)
{
    if(st==en)
    tree[node]=arr[st];
    else
    {
        ll mid=(st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        if(tree[2*node]<tree[2*node+1])
        tree[node]=tree[2*node];
        else
        tree[node]=tree[2*node+1];
    }
}
void update(ll node,ll st,ll en,ll id,ll y)
{
    if(st==en)
    {
        arr[id]=y;
        tree[node]=y;
    }
    else
    {
        ll mid=(st+en)/2;
        if(id>=st and id<=mid)
        update(2*node,st,mid,id,y);
        else
        update(2*node+1,mid+1,en,id,y);
        if(tree[2*node]<tree[2*node+1])
        tree[node]=tree[2*node];
        else
        tree[node]=tree[2*node+1];
            
    }
}
ll query(ll node,ll st,ll en,ll l,ll r)
{
    if(l>en or r<st)
    return 100005;
    if(st>=l and en<=r)
    return tree[node];
    else
    {
        ll mid=(st+en)/2;
        ll p1=query(2*node,st,mid,l,r);
        ll p2=query(2*node+1,mid+1,en,l,r);
        if(p1<p2)
        return p1;
        else
        return p2;
    }
}/*
int query(int node,int start,int end,int l,int r)
{
if(l>end||start>r)
return 100005;
if(l<=start&&r>=end)
return tree[node];
int p1,p2;
int mid=(start+end)/2;
p1=query(2*node,start,mid,l,r);
p2=query(2*node+1,mid+1,end,l,r);
if(p1<p2)
return p1;
else
return p2;
}*/
int main()
{
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
    cin>>arr[i];
    build(1,1,n);
    while(q--)
    {
        char x;
        cin>>x;
        ll a,b;
        if(x=='q')
        {
            cin>>a>>b;
            cout<<query(1,1,n,a,b)<<"\n";
        }
        else if(x=='u')
        {
            cin>>a>>b;
            update(1,1,n,a,b);
        }
    }
    return 0;
    
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll sum;
    ll prefix;
};
void build(ll nodee,ll st,ll en,ll arr[],node tree[])
{
    if(st==en)
    {
        tree[nodee].sum=arr[st];
        tree[nodee].prefix=arr[st];
        return ;
        
    }
    else
    {
        ll mid=(st+en)/2;
        build(2*nodee,st,mid,arr,tree);
        build(2*nodee+1,mid+1,en,arr,tree);
        tree[nodee].sum=tree[2*nodee].sum+tree[2*nodee+1].sum;
        tree[nodee].prefix=max(tree[2*nodee].prefix,tree[2*nodee].sum+tree[2*nodee+1].prefix);
        return ;
        
    }
}
node query(node tree[],ll nodee,ll st,ll en,ll l,ll r)
{
    node result;
    result.sum=-1;
    result.prefix=-1;
    if(l>en or r<st)
    return result;
    if(st>=l and en<=r)
    return tree[nodee];
    else
    {
        ll mid=(st+en)/2;
        if(l>mid)
        {
            return (query(tree,2*nodee+1,mid+1,en,l,r));
        }
        if(r<=mid)
        return (query(tree,2*nodee,st,mid,l,r));
        node left=query(tree,2*nodee,st,mid,l,r);
        node right=query(tree,2*nodee+1,mid+1,en,l,r);
        result.sum=left.sum+right.sum;
        result.prefix=max(left.prefix,left.sum+right.prefix);
        return result;
        
    }
    
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        ll arr[n+1];
        node tree[4*n+1];
        for(ll i=1;i<=n;i++)
        cin>>arr[i];
        build(1,1,n,arr,tree);
        while(q--)
        {
            ll a,b;
            cin>>a>>b;
            node ans=query(tree,1,1,n,a+1,b+1);
            cout<<ans.prefix<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

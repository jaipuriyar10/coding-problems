#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,i,j;
char a[510][510];
bool vis[510][510];
void f(ll x,ll y)
{
	if(x<0 || x>=n ||y<0|| y>=m)return;
	if(a[x][y]!='.')return;
	if(vis[x][y])return;
	vis[x][y]=true;
	f(x+1,y);f(x-1,y);f(x,y+1);f(x,y-1);
	if(k)a[x][y]='X',k--;
}
int main()
{
	cin>>n>>m>>k;
	for(ll i=0;i<n;i++)
	cin>>a[i];
	for(ll i=0;i<n && k;i++)
	for(ll j=0;j<m && k;j++)
	f(i,j);
	for(ll i=0;i<n;i++)
	cout<<a[i]<<"\n";
	return 0;
}
	
	

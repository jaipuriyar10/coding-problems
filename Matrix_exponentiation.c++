#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 52
typedef long long ll;
ll arr[N][N],I[N][N];
void multiply(ll A[][N],ll B[][N],ll n)
{
	ll res[n+1][n+1];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			res[i][j]=0;
			for(ll k=1;k<=n;k++)
			res[i][j]=((res[i][j]%mod)+((A[i][k]%mod)*(B[k][j]%mod))%mod)%mod;
		}
	}
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=n;j++)
	A[i][j]=res[i][j];
} 
void solve(ll A[][N],ll n,ll m)
{
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=n;j++)
	{
		if(i==j)
		I[i][j]=1;
		else
		I[i][j]=0;
	}
	while(m>0)
	{
		if(m%2)
		multiply(I,A,n),m--;
		else
		multiply(A,A,n),m/=2;
	}
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=n;j++)
	A[i][j]=I[i][j];
}
void print(ll A[][N],ll n)
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		cout<<A[i][j]<<" ";
		cout<<"\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
		cin>>arr[i][j];
		solve(arr,n,m);
		print(arr,n);
	}
	return 0;
}
	

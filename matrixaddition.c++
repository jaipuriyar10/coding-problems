#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mat[1003][1003];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
	ll n,m;
	cin>>n;
	m=n;
	memset(mat,-1,sizeof(mat));
	ll arr[n][m];
	for(ll i=0;i<n;i++)
	for(ll j=0;j<m;j++)
	cin>>arr[i][j];
	for(ll i=0;i<n;i++)
	{
		for(ll j=1;j<=i;j++)
		mat[i][j-1]=-1;
		for(ll k=0;k<m;k++)
		mat[i][(k+i)]=arr[i][k];
	}
	/*for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<2*m;j++)
		cout<<mat[i][j]<<"     ";
		cout<<"\n";
	}*/
	for(ll i=0;i<=(2*m-1);i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(mat[j][i]!=-1)
			cout<<mat[j][i]<<" ";
		}
	}
	cout<<"\n";
	}
	return 0;

}
		

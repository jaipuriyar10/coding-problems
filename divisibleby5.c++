#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m;
	cin>>n>>m;
	ll sum=0;
	for(ll i=1;i<=n;i++)
	{
		sum+=(m+i%5)/5;
	}
	cout<<sum<<"\n";
	return 0;
}

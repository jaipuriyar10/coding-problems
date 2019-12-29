#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
	cin>>a[i];
	ll b[n];
	b[0]=1;
	for(ll i=1;i<n;i++)
	{
		b[i]=1;
		for(ll j=0;j<i;j++)
		{
			if(a[i]>a[j] and b[i]<b[j]+1)
			b[i]=b[j]+1;
		}
	}
	cout<<*max_element(b,b+n)<<"\n";
	return 0;
}

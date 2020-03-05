#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string modified(string s,ll n,ll k)
{
	string resp=s.substr(k-1,n-k+1);
	string ress=s.substr(0,k-1);
	if(n%2==k%2)
	reverse(ress.begin(),ress.end());
	return (resp+ress);
}
int main()
{
	ll t;
	cin>>t;
	string s,best_s,temp;
	ll best_k;
	ll n;
	while(t--)
	{
		cin>>n>>s;
		best_s=modified(s,n,1);
		best_k=1;
		for(ll i=2;i<=n;i++)
		{
			temp=modified(s,n,i);
			if(temp<best_s)
			{
				best_s=temp;
				best_k=i;
			}
		}
		cout<<best_s<<"\n"<<best_k<<"\n";
	}
	return 0;
}

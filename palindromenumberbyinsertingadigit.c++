#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string str;
	cin>>str;
	ll n=str.size();
	for(ll i=0;i<=n;i++)
	{
		for(ll j='a';j<='z';j++)
		{
			string t=str.substr(0,i)+string(1,j)+str.substr(i);
			string u=t;
			reverse(u.begin(),u.end());
			if(u==t)
			{cout<<t<<"\n";
			goto end;}
		}
	}
	cout<<"NA"<<"\n";
	end:;
	return 0;
}

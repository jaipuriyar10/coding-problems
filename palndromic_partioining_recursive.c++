#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isp(string str,int i,int j)
{
	bool flag=false;
	while(i<=j)
	{

		if(str[i]==str[j])
		{
			i++;
			j--;
			flag=true;
		}
		else
		{flag=false;break;}
	}
	return flag;
}
ll solve(string str,ll i,ll j)
{
	if(i>=j)
	return 0;
	if(isp(str,i,j))
	return 0;
	else
	{
		ll res=INT_MAX;
		ll temp;
		for(ll x=i;x<j;x++)
		{
			temp=1+solve(str,i,x)+solve(str,x+1,j);
			res=min(res,temp);
		}
		return res;
	}
}
int main()
{
	string str;
	cin>>str;
	ll n=str.length();
	ll res=solve(str,0,n-1);
	cout<<res<<"\n";
	return 0;
}

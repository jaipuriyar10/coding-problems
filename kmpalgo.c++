#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> lp(string str)
{
	ll n=str.length();
	vector<ll>lps(n);
	lps[0]=0;
	for(ll i=1;i<n;i++)
	{
		ll j=lps[i-1];
		while(j>0 and str[i]!=str[j])j=lps[j-1];
		if(str[i]==str[j])j++;
		lps[i]=j;
	}
	return lps;
}
ll kmp(string str1,string str2)
{
	ll n,m;
	n=str2.length();
	m=str1.length();
	vector<ll> lps=lp(str1);
	ll i=0,j=0,cnt=0;
	while(i<n)
	{
		if(str1[j]==str2[i])
		i++,j++;
		if(j==m)
		cnt++,j=lps[j-1];
		else if(i<n && str1[j]!=str2[i])
		{
			if(j!=0)j=lps[j-1];
			else
			i++;
		}
	}
	return cnt;
}
int main()
{
	string str1,str2;
	cin>>str1>>str2;
	cout<<kmp(str1,str2);
	return 0;
}

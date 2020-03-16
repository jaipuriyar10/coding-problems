#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll len1,len2;
	string str,pat;
	cin>>str>>pat;
	len1=str.length();
	len2=pat.length();
	int hash_str[256];
	int hash_pat[256];
	memset(hash_str,0,sizeof(hash_str));
	memset(hash_pat,0,sizeof(hash_pat));
	for(ll i=0;i<len2;i++)
	hash_pat[(int)pat[i]]++;
	int cnt=0;
	int start=0;
	int id=-1;
	int minlen=INT_MAX;
	for(ll i=0;i<len1;i++)
	{
		hash_str[(int)str[i]]++;
		if(hash_str[(int)str[i]]<=hash_pat[(int)str[i]] and hash_pat[(int)str[i]]!=0)
		cnt++;
		if(cnt==len2)
		{
			while(hash_str[(int)str[start]]>hash_pat[(int)str[start]] || hash_pat[(int)str[start]]==0)
			{
				if(hash_str[(int)str[start]]>hash_pat[(int)str[start]])
				 hash_str[(int)str[start]]--;
				 start++;
			}
			int len=i-start+1;
			if(minlen>len)
			{
				minlen=len;
				id=start;
			}
		}
	}
	cout<<minlen<<"\n";
	return 0;
}
			

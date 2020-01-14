#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct trie
{
	ll stop;
	trie *next[10];
	trie()
	{
		stop=0;
		for(ll i=0;i<10;i++)
		next[i]=NULL;
	}
}*root;
bool insert(string str,trie *cur)
{
	ll l=str.size();
	bool test=0;
	for(ll i=0;i<l;i++)
	{
		ll now=str[i]-'0';
		if(cur->next[now]==NULL)
		cur->next[now]=new trie();
		if(cur->stop)
		{test=1;break;}
		cur=cur->next[now];
	}
	cur->stop=1;
	return test;
}
void del(trie *cur)
{
	for(ll i=0;i<10;i++)
	if(cur->next[i])
	del(cur->next[i]);
	delete(cur);
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		root=new trie();
		ll n;
		cin>>n;
		string str;
		vector<string> v;
		for(ll i=0;i<n;i++)
		{cin>>str;v.push_back(str);}
		sort(v.begin(),v.end());
		bool test=0;
		for(ll i=0;i<n;i++)
		{
			test=insert(v[i],root);
			if(test)break;
		}
		if(test)
		cout<<"NO"<<"\n";
		else
		cout<<"YES"<<"\n";
	}
	return 0;
}

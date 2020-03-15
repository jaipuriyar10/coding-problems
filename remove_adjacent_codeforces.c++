#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin>>t;
	string str;
	cin>>str;
	int cnt=0;
	int n=str.length();
	while(n--)
	{
		int id=-1;
		char x='a';
		for(int j=0;j<str.length();j++)
		{
			if((j-1)>=0 and (j+1)<str.length())
			if(str[j]==str[j-1]+1 or str[j]==str[j+1]+1)
			{
				if(x<=str[j])
				{
				x=str[j];
				id=j;
				}
			}
			if(j==0)
			{
				if(str[j]==str[j+1]+1)
				{
				if(x<=str[j])
				{
				x=str[j];
				id=j;
				}
				}
			}
			if(j==str.length()-1)
			{
				if(str[j]==str[j-1]+1)
				{
				if(x<=str[j])
				{
				x=str[j];
				id=j;
				}
				}
			}
		}
		if(id!=-1)
		{str.erase(id,1);cnt++;}
		if(str.length()==1)
		break;
		
	}
	cout<<cnt<<"\n";
	return 0;
}
 

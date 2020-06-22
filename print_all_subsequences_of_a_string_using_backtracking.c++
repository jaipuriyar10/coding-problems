#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//temporary string.
string temp;
//multiset for maintainging
//lexicographical order.
multiset<string>st;
//solve function which will make
//recursive calls
void solve(string str, ll pos)
{
	//insert in multiset.
	st.insert(temp);
	//iterate through all characters.
	for (ll i = pos; i < str.length(); i++)
	{
		//insert current character.
		temp.push_back(str[i]);
		//make recursive call.
		solve(str, i + 1);
		//backtrack
		temp.pop_back();
	}
}

int main()
{
	cout<<"Enter number of test cases: ";
	int t;
	cin >> t;
	while (t--)
	{
		st.clear();
		cout<<"Enter string: ";
		string str;
		cin >> str;
		temp = "";
		solve(str, 0);
		cout<<"Possible Subsequences in lexicographical order:";
		for(auto it=st.begin();it!=st.end();it++)
		cout<<*it<<"\n";
	}
	return 0;
}

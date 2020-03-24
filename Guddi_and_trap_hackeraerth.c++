problem:-https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/gudi-trapped-in-the-room-july-easy/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
#include<set>
set<string>st;
ll a,h;
void dfs(string str)
{
    string temp=str;
    st.insert(str);
    ll n=str.length();
    for(int i=0;i<n;i++)
    {
        temp[(i+h)%n]=str[i];
    }
    if(st.find(temp)==st.end())
    dfs(temp);
    for(int i=0;i<n;i++)
    {
        if(i%2)
        {
            str[i]='0'+(str[i]-'0'+a)%10;
        }
    }
    if(st.find(str)==st.end())
    dfs(str);
    return ;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cin>>a>>h;
        dfs(str);
        cout<<(*st.begin())<<"\n";
        st.clear();
    }
    return 0;
}

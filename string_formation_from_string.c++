problem:-https://practice.geeksforgeeks.org/problems/string-formation-from-substring/0/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        string st=str.substr(1);
        st=st+str;
        ll n=str.length();
        ll m=st.find(str)+1;
        if(n-m)
        cout<<"True\n";
        else
        cout<<"False\n";
    }
    return 0;
}

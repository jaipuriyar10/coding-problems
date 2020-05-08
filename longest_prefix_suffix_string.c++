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
        ll n=str.length();
        ll lps[n];
        lps[0]=0;
        ll i=1;
        ll len=0;
        while(i<n)
        {
            if(str[i]==str[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                len=lps[len-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        cout<<lps[n-1]<<"\n";
    }
    return 0;
}

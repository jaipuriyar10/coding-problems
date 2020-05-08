#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    //ll t;
    //cin>>t;
    //while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        ll n1=str1.length();
        ll n2=str2.length();
        ll lps[n1];
        lps[0]=0;
        ll len=0;
        ll i=1;
        while(i<n1)
        {
            if(str1[i]==str1[len])
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
        i=0;
        ll j=0;
        ll cnt=0;
        while(i<n2)
        {
            if(str1[j]==str2[i])
            {
                i++;
                j++;
            }
            if(j==n1)
            {
                cnt++;
                j=lps[j-1];
            }
            if(i<n2 and str1[j]!=str2[i])
            {
                if(j!=0)
                j=lps[j-1];
                else
                {
                    i++;
                }             
            
            }
        }
        cout<<cnt;
    }
}

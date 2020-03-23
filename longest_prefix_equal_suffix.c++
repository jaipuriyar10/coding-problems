problem:-https://leetcode.com/contest/weekly-contest-181/problems/longest-happy-prefix/

class Solution {
public:
    #define mod 1000000007
    string longestPrefix(string s) {
        
        long long  h1=0,h2=0,mul=1;
        long long  l1;
        for(int i=0,j=s.size()-1;j>0;i++,j--)
        {
            int fi=s[i]-'a';
            int la=s[j]-'a';
            h1=(((h1%mod)*(26%mod))%mod+fi)%mod;
            h2=(h2+(((la%mod)*(mul%mod))%mod))%mod;
            mul=((mul%mod)*(26%mod))%mod;
            if(h1==h2)
                len=i+1;
        }
        if(s.length()==1)
            return ("");
        else
        return s.substr(0,len);
        
        
        
        
        
    }
};

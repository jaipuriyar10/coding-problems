class Solution {
public:
    bool compare(unordered_map<char,int>m1,unordered_map<char,int>m2)
    {
        for(auto it=m2.begin();it!=m2.end();it++)
        {
            if(m1[it->first]!=it->second)
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length()>s2.length())
            return false;
        
        unordered_map<char,int>m1,m2;
        for(int i=0;i<s1.length();i++)
        {m2[s1[i]]++;m1[s2[i]]++;}
        
        for(int i=s1.length();i<s2.length();i++)
        {
            if(compare(m1,m2))
                return true;
            m1[s2[i]]++;
            m1[s2[i-s1.length()]]--;
        }
        if(compare(m1,m2))
            return true;
        else
            return false;
        
        
        
    }
};

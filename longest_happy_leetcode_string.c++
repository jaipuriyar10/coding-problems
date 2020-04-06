problem:-https://leetcode.com/contest/weekly-contest-183/problems/longest-happy-string/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
    
        string str;
        str="";
        priority_queue<pair<int,char>>pq;
        if(a)
        pq.push({a,'a'});
        if(b)
        pq.push({b,'b'});
        if(c)
        pq.push({c,'c'});
        while(pq.size()>1)
        {
            pair<int,char>p1,p2;
            p1=pq.top();
            pq.pop();
            p2=pq.top();
            pq.pop();
            if(p1.first>=2)
            {
                str+=p1.second;
                str+=p1.second;
                p1.first-=2;
            }
            else 
            {
                str+=p1.second;
                p1.first-=1;
            }
            if(p2.first>=2 and p2.first>=p1.first)
            {
                str+=p2.second;
                str+=p2.second;
                p2.first-=2;
            }
            else 
            {
                str+=p2.second;
                p2.first-=1;
            }
            if(p1.first>0)
            pq.push(p1);
            if(p2.first>0)
            pq.push(p2);
        }
        if(pq.empty())
            return str;
        else
        {
            if(pq.top().first>=2 and str[str.length()-1]!=pq.top().second)
            {
                str+=pq.top().second;
                str+=pq.top().second;
                pair<int,char> p1=pq.top();
                pq.pop();
                p1.first-=2;
                pq.push(p1);
            }
            else if(str[str.length()-1]!=pq.top().second)
            {
                str+=pq.top().second;
                pair<int,char> p1=pq.top();
                pq.pop();
                p1.first-=1;
                pq.push(p1);
            
            }
        }
        return str;
    
    
    }
};

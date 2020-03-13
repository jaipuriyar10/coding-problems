class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&ma,int t,int target,int curver,double curpro,double &res)
    {
        if(t==0)
        {
            if(curver==target)
                res=curpro;
            return ;
        }
        if(ma[curver].empty())
        {
            dfs(ma,t-1,target,curver,curpro,res);
        }
        else
        {
            curpro=curpro*((1.0)/(ma[curver].size()));
            for(auto x:ma[curver])
            {
                dfs(ma,t-1,target,x,curpro,res);
            }
        }
        
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
     
        unordered_map<int,vector<int>>ma;
        for(auto x:edges)
        {
            int f=min(x[0],x[1]);
            int to=max(x[0],x[1]);
            ma[f].push_back(to);
        }
        double res=0.0;
        dfs(ma,t,target,1,1.0,res);
        return res;
        
        
    }
};

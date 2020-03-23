problem:-https://leetcode.com/contest/weekly-contest-181/problems/check-if-there-is-a-valid-path-in-a-grid/
class Solution {
public:
    bool help(int i,int j,int n,int m,vector<vector<int>>&dp,vector<vector<int>>&grid,int l)
    {
        if(i<0||i>=n||j<0||j>=m||dp[i][j])
            return false;
        if((l==1 && grid[i][j]==2)||(l==2 &&grid[i][j]==1))
            return false;
        else if(i==n-1 and j==m-1)
            return true;
        dp[i][j]=1;
        switch(grid[i][j])
        {
            case 1:return help(i,j+1,n,m,dp,grid,1)||help(i,j-1,n,m,dp,grid,1);
            case 2:return help(i+1,j,n,m,dp,grid,2)||help(i-1,j,n,m,dp,grid,2);
            case 3:return help(i+1,j,n,m,dp,grid,3)||help(i,j-1,n,m,dp,grid,3);
            case 4:return help(i,j+1,n,m,dp,grid,4)||help(i+1,j,n,m,dp,grid,4);
            case 5:return help(i-1,j,n,m,dp,grid,5)||help(i,j-1,n,m,dp,grid,5);
            case 6:return help(i-1,j,n,m,dp,grid,6)||help(i,j+1,n,m,dp,grid,6);
            default:return false;
        }
        
        
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
        return help(0,0,n,m,dp,grid,0);  
       
    }
};

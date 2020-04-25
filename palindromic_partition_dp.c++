int dp[504][504];
bool isp(string str,int i,int j)
{
    bool flag=false;
    while(i<=j)
    {
        if(str[i]==str[j])
        {
            i++;
            j--;
            flag=true;
        }
        else
        {
            flag=false;
            break;
        }
    }
    return flag;
}
int solve(string str,int i,int j)
{
    if(i>=j)
    return 0;
    if(isp(str,i,j))
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int res=INT_MAX;
    int temp;
    for(int x=i;x<j;x++)
    {
        int left,right;
        if(dp[i][x]!=-1)
        left=dp[i][x];
        else
        {
            left=solve(str,i,x);
            dp[i][x]=left;
        }
        if(dp[x+1][j]!=-1)
        right=dp[x+1][j];
        else
        {
            right=solve(str,x+1,j);
            dp[x+1][j]=right;
        }
        temp=1+left+right;
        res=min(res,temp);
    }
    dp[i][j]=res;
    return dp[i][j];
}
int Solution::minCut(string A) {
    
    memset(dp,-1,sizeof(dp));
    int n=A.length();
    int res=solve(A,0,n-1);
    return res;
    
    
    
}

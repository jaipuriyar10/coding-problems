lass Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
     
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int ls=0;
            int j;
            //int prev,cur;
            for(j=2;j*j<=nums[i];j++)
            {
                
                if(nums[i]%j==0)
                {
                    if(ls==0)
                        ls=j;
                    else 
                    {
                        ls=0;
                        break;
                    }
                    
                }
            }
            if(ls and nums[i]/ls!=ls)
            {
                sum+=(nums[i]+1);
                sum+=ls;
                sum+=nums[i]/ls;
            }
        
        }
        return sum;
        
        
    }
};

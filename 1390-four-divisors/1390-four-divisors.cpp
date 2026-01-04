class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
           int result=div(nums[i]);
            if(result)
            ans+=result;
        }
        if(ans)
        return ans;
        return 0;
    }

    int div(int n)
    {
        int count=1;
        int sol=0;
        for(int i=1;i<=n/2;i++)
        {
            if(n%i==0)
            {
            count++;
            sol+=i;
            }
            if(count>4)
            return 0;
        }
        if(count==4)
        return sol+n;
        
        return 0;
    }
};
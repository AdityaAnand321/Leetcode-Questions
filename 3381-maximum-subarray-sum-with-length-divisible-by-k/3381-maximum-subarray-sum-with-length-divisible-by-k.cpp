class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = -10000000;

        for(int i=0;i<nums.size();i++)
        {
            long long int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                if( (j-i+1)%k==0)
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};
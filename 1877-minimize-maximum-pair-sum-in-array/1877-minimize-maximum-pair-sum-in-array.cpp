class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=n-1;
        int ans=0;

        for(int i=0;i<n/2;i++)
        {
            ans=max(ans,nums[left]+nums[right]);
            right--;
            left++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        int n=nums.size();
        sub(0,nums,curr,ans);
        return ans;
    }

    void sub(int i,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        if(i==nums.size())
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        sub(i+1,nums,curr,ans);

        curr.pop_back();
        sub(i+1,nums,curr,ans);
    }
};
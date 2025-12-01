class Solution {
public:
    vector<vector<int>>ans;
    vector<int>a;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        func(0,a,nums,n);
        return ans;
    }

    void func(int i,vector<int>&a,vector<int>&arr,int n)
    {
        if(i==n)
        {
            ans.push_back(a);
            return;
        }

        a.push_back(arr[i]);
        func(i+1,a,arr,n);
        a.pop_back();
        func(i+1,a,arr,n);
    }


};
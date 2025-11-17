class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int seen=-1;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                if(seen!=-1 && i-seen-1<k)
                return false;

                 seen=i;
            }
           
        }
        return true;
    }
};
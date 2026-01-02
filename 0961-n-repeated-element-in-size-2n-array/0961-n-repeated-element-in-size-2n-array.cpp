class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        int n1=n/2;

        unordered_map<int,int>count;
        for(int a:nums)
        count[a]++;

        for(auto&it: count)
        {
            if(it.second==n1)
            return it.first;
        }

        return -1;
    }
};
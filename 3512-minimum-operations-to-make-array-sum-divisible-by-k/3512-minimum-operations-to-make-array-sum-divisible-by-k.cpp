class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(int a:nums)
        sum+=a;

        return sum%k;
    }
};
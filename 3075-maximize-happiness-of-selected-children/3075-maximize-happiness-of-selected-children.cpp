class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
        
        sort(hap.begin(),hap.end(),greater<>());
        int sum=0;
        int i=0;
        while(k--)
        {   
            if(hap[i]-i>0)
            sum+=hap[i]-i;
            i++;
        }
        return sum;

    }
};
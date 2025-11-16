class Solution {
public:
    int numSub(string s) {
        int n=s.size();
        constexpr int kMod = 1'000'000'007;
     int ans=0;

        for(int i=0;i<n;i++)
        {   
        
            for(int j=i;j<n;j++)
            {
                if(s[j]=='1'){
                ans=(ans+1)%kMod;
                
                }
                else 
                break;
            }
        }
        return ans;
    }
};
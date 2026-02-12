class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            vector<int>freq(26,0);

            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;

                  int minFreq=INT_MAX;
            int maxFreq=0;

            for(int i=0;i<26;i++)
            {
                if(freq[i]>0)
                {
                    minFreq=min(minFreq,freq[i]);
                    maxFreq=max(maxFreq,freq[i]);
                }
            }

            if(minFreq==maxFreq)
            ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
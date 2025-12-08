class Solution {
public:
    int dp[301][11];  
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if (n < d) return -1;    
        memset(dp, -1, sizeof(dp));
        return diff(jd, n, 0, d);
    }
    int diff(vector<int>& jd, int n, int index, int d) {
          if (d == 1) {
            int maxD = jd[index];
            for (int i = index; i < n; i++)
                maxD = max(maxD, jd[i]);
            return maxD;
        } 
           if (dp[index][d] != -1)
            return dp[index][d];

        int ans = INT_MAX;
        int currMax = 0;  for (int i = index; i <= n - d; i++) {
            currMax = max(currMax, jd[i]);          
            int next = diff(jd, n, i + 1, d - 1);     
            ans = min(ans, currMax + next);
        }
             return dp[index][d] = ans;
    }
};

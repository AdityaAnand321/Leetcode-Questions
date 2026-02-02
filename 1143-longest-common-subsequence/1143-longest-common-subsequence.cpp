class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }

    int ans(string s1,string s2,int n,int m)
    {   
        if(n==0|| m==0)
        return 0;

        if(s1[n-1]==s2[m-1])
        {
            return 1+ans(s1,s2,n-1,m-1);
        }
        else
        return max(ans(s1,s2,n-1,m),ans(s1,s2,n,m-1));
    }
};
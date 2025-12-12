class Solution {
public:
    int minDistance(string word1,string word2){
        int n=word1.size(),m=word2.size();
        if(m==0) return n;
        vector<int> prev(m+1);
        for(int j=0;j<=m;j++) prev[j]=m-j;
        for(int i=n-1;i>=0;i--){
            vector<int> curr(m+1);
            curr[m]=n-i;
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]) curr[j]=prev[j+1];
                else{
                    int insertOp=1+curr[j+1];
                    int deleteOp=1+prev[j];
                    int replaceOp=1+prev[j+1];
                    curr[j]=min(min(insertOp,deleteOp),replaceOp);
                }
            }
            prev=move(curr);
        }
        return prev[0];
    }
};

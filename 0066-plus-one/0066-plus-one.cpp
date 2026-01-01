class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int carry=0;
        vector<int>ans;
        int n=d.size();
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                d[i]=d[i]+1;
                if(d[i]>9)
                {
                    d[i]=0;
                    carry++;
                }
            }
            
            else if(carry>0)
            {
                d[i]+=1;
                if(d[i]>9)
                {d[i]=0;
                carry++;}
                carry--;
            }

            ans.push_back(d[i]);
        }
        if(carry==1)
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
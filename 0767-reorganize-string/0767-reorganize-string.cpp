class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();

        vector<int>freq(26,0);//isme characters ki frequency store karli

        for(char c:s)
        freq[c-'a']++;

        int maxFreq=0,maxChar=0; //isme maxm character ka frequency and character store karliya
        for(int i=0;i<26;i++)
        {
            if(maxFreq<freq[i])
            {
            maxFreq=freq[i];
            maxChar=i;
            }
        }

        if(maxFreq>(n+1)/2)//because arrange possible hoga ny agar n/2 se jada hoga to
        return "";

        vector<char>ans(n);
        int index=0;

        while(freq[maxChar]>0)
        {
            ans[index]=maxChar+'a';
            index+=2;
            freq[maxChar]--;
        }

        for(int i=0;i<26;i++)
        {
            while(freq[i]>0)
            {
                if(index>=n)
                index=1;

                ans[index]=i+'a';
                index+=2;
                freq[i]--;
            }
        }

        return string(ans.begin(),ans.end());
    }
};
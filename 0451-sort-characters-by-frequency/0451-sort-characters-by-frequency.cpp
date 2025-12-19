class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;

        int n=s.size();
        for(char c:s)
        {  
            mp[c]++;
        }
        vector<pair<int,char>>vp;

        for(auto &it:mp)
        {
            vp.push_back({it.second,it.first});
        }

        sort(vp.begin(),vp.end(),greater<>());
        string result="";

        for(auto &it: vp)
        {
            result.append(it.first,it.second);
        }
        return result;

    }
};
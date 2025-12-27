class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        // find max frequency character
        int maxFreq = 0, maxChar = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        // if not possible
        if (maxFreq > (n + 1) / 2)
            return "";

        vector<char> ans(n);
        int index = 0;

        // fill most frequent character at even positions
        while (freq[maxChar] > 0) {
            ans[index] = maxChar + 'a';
            index += 2;
            freq[maxChar]--;
        }

        // fill remaining characters
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (index >= n)
                    index = 1;

                ans[index] = i + 'a';
                index += 2;
                freq[i]--;
            }
        }

        return string(ans.begin(), ans.end());
    }
};

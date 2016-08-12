class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        vector<int> charLastIndex(256,-1);
        int maxLen = 0, start = -1;
        for(int i=0;i<s.length();++i) {
            if(charLastIndex[s[i]]>start)
                start = charLastIndex[s[i]];
            charLastIndex[s[i]] = i;
            maxLen = max(maxLen,i-start);
        }
        
        return maxLen;
    }
};

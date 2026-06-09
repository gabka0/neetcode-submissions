class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l=0;
        int max = 0;
        for(int i=0; i<s.size();i++){
            while(seen.contains(s[i])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[i]);
            if(i-l+1>max) max = i-l+1;
        }
        return max;
    }
};

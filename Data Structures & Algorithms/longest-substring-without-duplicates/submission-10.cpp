class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int max = 0;
        int l=0;
        for(int i=0; i<s.size();i++){
            if(seen.contains(s[i])){
                while(s[l]!=s[i]){
                    seen.erase(s[l]);
                    l++;
                }
                l++;
            }
            else{
                if(i-l+1>max) max=i-l+1;
                seen.insert(s[i]);
            }
        }
        return max;
    }
};

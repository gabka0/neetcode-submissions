class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> x;
        int start = 0;
        int max = 0;
        for(int i=0;i<s.size();i++){
            if(x.contains(s[i])){
                while(start<i){
                    x.erase(s[start]);
                    if(s[start]==s[i]) {
                        start++;
                        break;
                    }
                    start++;
                }
            }
            x.insert(s[i]);
            if(i-start+1>max) max=i-start+1;
        }
        return max;
        
    }
};

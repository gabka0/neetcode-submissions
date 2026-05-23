class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        int L = 0;
        int maxSize = 1;
        unordered_set<char> mySet; 
        for(int R=0; R<s.length(); R++){
            if(mySet.find(s[R]) != mySet.end()){
    while (mySet.find(s[R]) != mySet.end()) { // duplicate in window
        mySet.erase(s[L]);
        ++L;
    }
            }
            if(R-L+1>maxSize){
                maxSize=R-L+1;
            }
            mySet.insert(s[R]);
        }
        return maxSize;
    }
};

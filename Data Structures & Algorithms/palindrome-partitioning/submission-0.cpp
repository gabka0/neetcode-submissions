class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> subset;
        vector<string> curset;
        helper(s, subset, curset, 0);
        return subset;

        
    }
    void helper(string& s, vector<vector<string>>& subset, vector<string>& curset, int cur){
        if(cur==s.size()) {
            subset.push_back(curset);
            return;
        }
        string tmp;
        for(int i=cur; i<s.size();i++){
            tmp.push_back(s[i]);
            if(isPalindrome(tmp)) {
                curset.push_back(tmp);
                helper(s, subset,curset,i+1);
                curset.pop_back();
                  
        }
    }
    }
    bool isPalindrome(string s){
        for(int i=0; i<s.size()/2; i++){
            if(s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }
};

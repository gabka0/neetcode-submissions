class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> curset;
        vector<vector<string>> answer;
        helper(s, curset, answer, 0);
        return answer;
    }
    void helper(string& s, vector<string>& curset, vector<vector<string>>& answer, int cur){
        if(cur>=s.size()) {
            answer.push_back(curset);
            return;
        }
        string tmp;
        for(int i=cur; i<s.size();i++){
            tmp+=s[i];
            if(isPalindrome(tmp)){
                curset.push_back(tmp);
                helper(s, curset, answer, i+1);
                curset.pop_back();
            }
        }
    }
    bool isPalindrome(string s){
        return s==string(s.rbegin(), s.rend());
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string> subset;
        string curset;
        helper(subset, curset, open, close, n);
        return subset;
    }
    void helper(vector<string>& subset, string& curset, int open,int close , int n){
        if(open>=n && close>=n){
            subset.push_back(curset);
            return;
        }
        if(open<n){
            curset.push_back('(');
            helper(subset, curset, open+1, close, n);
            curset.pop_back();
        }
        if(close<open){
            curset.push_back(')');
            helper(subset, curset, open, close+1, n);
            curset.pop_back();
        }

        


    }
};

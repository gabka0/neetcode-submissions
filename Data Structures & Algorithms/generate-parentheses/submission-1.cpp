class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string curset;
        helper(answer, n, 0, 0, curset);
        return answer;
        
    }
    void helper(vector<string>& answer, int n, int open, int close, string& curset){
        if(open>=n && close>=n){
            answer.push_back(curset);
            return;
        }
        if(open<n){
        curset.push_back('(');
        helper(answer, n, open+1, close, curset);
        curset.pop_back();
        }

        if(open>close){
            curset.push_back(')');
            helper(answer, n, open, close+1, curset);
            curset.pop_back();
        }



    }
};

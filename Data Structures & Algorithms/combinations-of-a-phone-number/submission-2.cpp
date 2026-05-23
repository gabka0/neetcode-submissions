class Solution {
public:
vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> subset;
        string curString;
        int cur = 0;
        if(digits=="") return subset;
        helper(subset, curString, digits, cur);

        return subset;
        
    }
    void helper(vector<string>& subset, string& curString, string& digits, int cur){
        if(cur==digits.length()){
            subset.push_back(curString);
            return;
        }
        for(char x: digitToChar[digits[cur]-'0']){
            curString.push_back(x);
            helper(subset, curString, digits, cur+1);
            curString.pop_back();
        }



    }
};

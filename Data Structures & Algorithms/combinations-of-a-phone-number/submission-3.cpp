class Solution {
unordered_map<char, string> x = {{'2', "abc"}, {'3',"def"}, {'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"}, {'8',"tuv"},{'9',"wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        string cur;
        vector<string> answer;
        if(digits=="") return answer;
        helper(digits, cur, answer, 0);
        return answer;
    }
    void helper(string& digits, string& cur, vector<string>& answer, int i){
        if(i>=digits.size()) {
            answer.push_back(cur);
            return;
        }
        for(char k: x[digits[i]]){
            cur.push_back(k);
            helper(digits, cur, answer,i+1);
            cur.pop_back();
        }

    }
};

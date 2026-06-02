class Solution {
    vector<int> memo;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size(), -1);
        return dfs(s, wordDict, 0);

    }
    bool dfs(string s, vector<string>& wordDict, int i){
        if(i==s.length()) {
            return true;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        for(string& w: wordDict){
            if(s.substr(i, w.length())==w){
                if(dfs(s, wordDict, i+w.length())){
                    memo[i] = 1;
                    return true;
                };
            }
        }
        memo[i] = 0;
        return false;

    }
};

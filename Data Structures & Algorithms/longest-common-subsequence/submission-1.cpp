class Solution {
private:
vector<vector<int>> memo;
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size(), vector<int>(text2.size(), -1));
        return dfs(0, 0, text1, text2);
        }
        
    
    int dfs(int i, int j, string& text1, string& text2){
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(text1[i]==text2[j]){
            memo[i][j] = 1+dfs(i+1, j+1, text1, text2);
           
        }
        else{
            memo[i][j] = max(dfs(i, j+1, text1, text2),dfs(i+1, j, text1, text2));
        }
        return memo[i][j];
    }
};

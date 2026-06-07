class Solution {
vector<vector<int>> memo;
public:
    int minDistance(string word1, string word2) {
        memo.assign(word1.size()+1, vector<int>(word2.size()+1,-1));
        return dfs(word1, word2, 0, 0);
    }
    int dfs(string& word1, string& word2, int i, int j){
        if(i==word1.size() && j==word2.size()) return 0;
        else if(memo[i][j]!=-1) return memo[i][j];
        else if(i==word1.size()) memo[i][j] = word2.size()-j;
        else if(j==word2.size()) memo[i][j] = word1.size()-i;
        else if(word1[i]==word2[j]){
            memo[i][j] = dfs(word1, word2, i+1, j+1);
        }
        else if(word1[i]!=word2[j]){
            memo[i][j] = min({1+dfs(word1, word2,i+1,j), 1+dfs(word1, word2,i,j+1), 1+dfs(word1, word2, i+1, j+1)});
        }
        return memo[i][j];

    }
};

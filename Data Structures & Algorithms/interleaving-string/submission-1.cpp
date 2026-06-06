class Solution {
private:
vector<vector<int>> memo;
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        memo.assign(s1.size()+1, vector<int>(s2.size()+1, -1));
        return dfs(s1, s2, s3, "", 0, 0, 0);
        
    }
    int dfs(string s1, string s2, string s3, string cur, int i, int j, int k){
        if(k==s3.size()){
            return cur==s3;
        }
        if(memo[i][j]!=-1) return memo[i][j];
        if(s2[j]!=s3[k] && s1[i]!=s3[k]){
            memo[i][j] = 0;
        }
        else if(s1[i]==s3[k] && s2[j]==s3[k]){
            memo[i][j] = dfs(s1, s2, s3, cur+s1[i], i+1, j,k+1) || dfs(s1, s2, s3, cur+s2[j], i, j+1,k+1);
        }
        else if(s1[i]==s3[k] && s2[j]!=s3[k]){
            memo[i][j] = dfs(s1, s2, s3, cur+s1[i], i+1, j,k+1);
        }
        else{
            memo[i][j]= dfs(s1, s2, s3, cur+s2[j], i, j+1,k+1);
        }
        return memo[i][j];
    }
};

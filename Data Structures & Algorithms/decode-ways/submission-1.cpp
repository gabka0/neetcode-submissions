class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo (s.size(), -1);
        return dfs(s, 0, memo);
        
    }
    int dfs(string s, int i, vector<int>& memo){
        if(i==s.size()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(memo[i]!=-1) return memo[i];
        int ans = dfs(s, i+1, memo);
        if(i+1<s.size()){
        int k = s[i]-'0';
        int l = s[i+1]-'0';
        if(10<=10*k+l && 26>=10*k+l){
            ans += dfs(s, i+2, memo);
        }
        }
        memo[i] = ans;
        return ans;
    }
};

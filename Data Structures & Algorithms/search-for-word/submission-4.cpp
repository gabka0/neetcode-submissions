class Solution {
private: 
vector<vector<int>> dfs = {{0, 1}, {0,-1}, {1, 0}, {-1,0}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size();i++){
            for(int j=0; j<board[0].size();j++){
                if(helper(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;


        
    }
    bool helper(vector<vector<char>>& board, string word, int index, int i, int j){
        if(index==word.size()){
            return true;
        } 
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || word[index]!=board[i][j]|| board[i][j]=='#') return false;
        char x = board[i][j];
        board[i][j] = '#';
        for(int k=0; k<4; k++){
            int newI = i + dfs[k][0];
            int newJ = j + dfs[k][1];
            if(helper(board, word, index+1, newI, newJ)) return true;
        }
        board[i][j] = x;
        return false;

    }
};

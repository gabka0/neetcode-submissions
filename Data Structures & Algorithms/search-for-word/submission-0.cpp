class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        string curset;
        for(int i =0; i<board.size();i++){
            for(int j=0; j<board[0].size();j++){
                if(helper(board, word, 0, i, j)) return true;
            }
        }
        return false;
        
        
    }
    bool helper(vector<vector<char>>& board, string& word, int index
    , int x, int y){
        if(index==word.size()) return true;
        if(x>=board.size() || x<0 || y>=board[0].size()|| y<0 ){
            return false;
        }
        if(board[x][y]==word[index]){
            board[x][y]='#';
        }
        else{
            return false;
        }
        if(helper(board, word, index+1, x+1, y) ||
        helper(board, word, index+1, x-1, y) ||
        helper(board, word, index+1, x, y-1)||
        helper(board, word, index+1, x, y+1)){
            return true;
        }
        board[x][y]=word[index];
        return false;


    }
};

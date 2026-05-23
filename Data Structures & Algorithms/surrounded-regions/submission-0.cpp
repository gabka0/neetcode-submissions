class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void solve(vector<vector<char>>& board) {
        int width = board[0].size();
        int height = board.size();
        for(int i=0; i<width; i++){
            if(board[0][i]=='O'){
                dfs(0,i, board);
            }
            if(board[height-1][i]=='O'){
                dfs(height-1,i, board);
            }

        }
        for(int j=1; j<height-1; j++){
            if(board[j][0]=='O') dfs(j,0,board);
            if(board[j][width-1]=='O') dfs(j, width-1,board);
        }

        for(int i=1; i<height-1;i++){
            for(int j=1; j<width-1;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
        
    }
    void dfs(int r, int c, vector<vector<char>>& board){
        for (int i = 0; i < 4; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            if(nr < board.size()-1 && nr >= 1 && nc < board[0].size()-1 && nc >= 1 && board[nr][nc]=='O'){
               board[nr][nc]='#'; 
               dfs(nr, nc, board);
            }
        }

    }
};

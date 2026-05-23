class Solution {
public:
 int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));
        vector<vector<int>> ans;
        for(int i=0; i<rows;i++){
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, cols-1);
        }
        for(int i=0;i<cols;i++){
            dfs(heights, pac, 0, i);
            dfs(heights, atl, rows-1,i);
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(atl[i][j] && pac[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

        
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c){
        ocean[r][c] = true;
        int rows = heights.size();
        int cols = heights[0].size();
        for (int i = 0; i < 4; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]){
               dfs(heights, ocean, nr, nc);
            }
        }
    }
};
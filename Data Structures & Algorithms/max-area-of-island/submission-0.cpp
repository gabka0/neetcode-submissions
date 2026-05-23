class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int maxArea = 0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<columns;c++){
                int area = dfs(grid, r, c);
                if(area>maxArea){
                    maxArea = area;
                }
            }
        }
        return maxArea;
        
    }
    int dfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size();
        int columns = grid[0].size();
        if(r>=rows || c>=columns || r<0 || c<0 || grid[r][c]==0){
            return 0;
        }
        int res = 1;
        grid[r][c]=0;
        res+=dfs(grid, r, c+1);
        res+=dfs(grid, r, c-1);
        res+=dfs(grid, r-1, c);
        res+=dfs(grid, r+1, c);
        return res;
    }
};

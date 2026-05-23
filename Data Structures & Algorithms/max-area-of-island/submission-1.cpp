class Solution {
    int count = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int maxArea = 0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<columns;c++){
                dfs(grid, r, c);
                if(count>maxArea){
                    maxArea = count;
                }
                count = 0;
            }
        }
        return maxArea;
        
    }
    void dfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size();
        int columns = grid[0].size();
        if(r>=rows || c>=columns || r<0 || c<0 || grid[r][c]==0){
            return;
        }
        grid[r][c]=0;
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        count+=1;
    }
};

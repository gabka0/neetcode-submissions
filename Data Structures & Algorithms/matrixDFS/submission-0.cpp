class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int rows =  grid.size();
        int columns = grid[0].size();
        vector<vector<int>> visit(rows, vector<int>(columns, 0));
        return dfs(grid, 0, 0,  rows, columns, visit);
        
    }
    int dfs(vector<vector<int>>& grid, int r, int c, int rows, int columns, vector<vector<int>>& visit){
        if(r<0 || c<0 || r==rows || c==columns || grid[r][c]==1 || visit[r][c]==1){
            return 0;
        }
        if (r == rows - 1 && c == columns - 1)
            return 1;
        visit[r][c]=1;
        int count = 0;
        count+=dfs(grid, r+1, c, rows, columns, visit);
        count+=dfs(grid, r-1, c, rows, columns, visit);
        count+=dfs(grid, r, c+1, rows, columns,visit);
        count+=dfs(grid, r, c-1, rows, columns, visit);
        visit[r][c]=0;
        return count;
        
    }
};

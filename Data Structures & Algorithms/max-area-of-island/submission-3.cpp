class Solution {
    vector<vector<int>> x = {{0,1}, {0,-1},{1,0},{-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]==1){
                int answer = dfs(grid, i, j);
                if(answer>max) max = answer;
                }
            }
        }
        return max;
        
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]==0) return 0;
        int count = 1;
        grid[i][j] = 0;
        for(int k=0; k<4;k++){
            count += dfs(grid, i+x[k][0], j+x[k][1]);
        }
        return count;
    }

};

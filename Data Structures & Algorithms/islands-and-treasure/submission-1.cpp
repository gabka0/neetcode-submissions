class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> visit (rows, vector<int>(cols));
        queue<pair<int,int>> q; 
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]==2147483647 || grid[i][j]==-1) continue;
                q.push({i, j});
                visit[i][j]=1;
            }
        }
        int length = 0;
        while(q.size()){
            int qlen = q.size();
            for(int k=0; k<qlen; k++){
                pair<int, int> curPair = q.front();
                q.pop();
                int r = curPair.first, c = curPair.second;
                int neighbors[4][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c}};
                for (int l = 0; l < 4; l++) {
                   int newR = neighbors[l][0], newC = neighbors[l][1];
                    if (min(newR, newC) < 0 || newR == rows || newC == cols
                    || visit[newR][newC] || grid[newR][newC]==-1) {
                    continue;
                }
                grid[newR][newC] = grid[r][c]+1;
                q.push(pair<int, int>(newR, newC));
                visit[newR][newC] = 1;
            }
            }
            length++;
        }
        
    }
};


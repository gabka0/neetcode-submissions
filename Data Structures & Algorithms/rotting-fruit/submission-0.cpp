class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> rotten_coor;
        vector<vector<int>> fresh_coor;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    rotten_coor.push_back({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh_coor.push_back({i, j});
                }
            }
        }

        int length = 0;
        while (fresh_coor.size()) {
            int size = rotten_coor.size();
            for (int i=0; i<size; i++) {
                int r = rotten_coor[i][0];
                int c = rotten_coor[i][1];
                vector<vector<int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (vector<int>& neighbor : neighbors) {
                    int dr = neighbor[0], dc = neighbor[1];
                    if (r + dr < 0 || c + dc < 0 || r + dr == rows || c + dc == cols ||
                        grid[r + dr][c + dc] == 2 || grid[r + dr][c + dc] == 0) {
                        continue;
                    }
                    fresh_coor.pop_back();
                    rotten_coor.push_back({r + dr, c + dc});
                    grid[r+dr][c+dc] = 2;
                }
            }
            if(size==rotten_coor.size()){
                return -1;
            }
            length += 1;
        }

        return length;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]==1) fresh++; 
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        int ans = 0;
        while(fresh>0 && !q.empty()){
            int size = q.size();
            for(int j=0; j<size;j++){
            pair<int, int> temp = q.front();
            q.pop();
            for(int i=0; i<4;i++){
                int newR = temp.first+dr[i];
                int newC = temp.second + dc[i];
                if(newR>=0 && newR<grid.size() && newC>=0 && newC<grid[0].size() && grid[newR][newC]==1){
                    grid[newR][newC] = 2;
                    q.push({newR, newC});
                    fresh--;
                }
            }
            }
            ans++;  
        }
        if(fresh>0) return -1;
        return ans;
        
    }
};

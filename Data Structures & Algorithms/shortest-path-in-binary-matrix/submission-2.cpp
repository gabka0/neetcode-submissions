class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        if(grid[0][0]) return -1;
        q.push({0,0});
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visit(rows, vector<int>(cols));
        visit[0][0] = 1;
        int length = 1;
        while(q.size()){
            int l = q.size();
            for(int i=0; i<l; i++){
                pair<int, int> cur = q.front();
                q.pop();
                int r = cur.first, c = cur.second;
                if(r==rows-1 && c==cols-1) return length;
                vector<vector<int>> neighbors = {{r,c+1}, {r,c-1}, {r+1,c}, {r-1,c}, {r+1, c+1}, {r-1, c-1},{r-1, c+1}, {r+1, c-1}};
                for(auto& x: neighbors){
                    int newR = x[0], newC = x[1];
                    if(newR>=rows || newC>=cols || newR<0 || newC<0 || visit[newR][newC]|| grid[newR][newC]){
                        continue;
                    }
                    q.push({newR, newC});
                    visit[newR][newC] = 1;
                }
            }
            length+=1;
        }
        return -1;
        

        
    }
};
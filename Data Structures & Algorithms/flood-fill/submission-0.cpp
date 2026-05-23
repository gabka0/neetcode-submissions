class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(),0));
        int init = image[sr][sc];
        dfs(image, visited, sr, sc, color, init);
        return image;


    }
    void dfs(vector<vector<int>>& image, vector<vector<int>>& visited, int sr, int sc, int color, int initial){
        if(min(sr,sc)<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=initial || visited[sr][sc]){
            return;
        }
        else{
            image[sr][sc] = color;
            visited[sr][sc] = 1;
        }
        dfs(image, visited, sr+1, sc, color, initial);
        dfs(image, visited, sr-1, sc, color, initial);
        dfs(image, visited, sr, sc+1, color, initial);
        dfs(image, visited, sr, sc-1, color, initial);
    }
};
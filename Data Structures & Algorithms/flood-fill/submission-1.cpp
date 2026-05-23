class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init = image[sr][sc];
        if(color==init){
            return image;
        }
        dfs(image, sr, sc, color, init);
        return image;


    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int initial){
        if(min(sr,sc)<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=initial){
            return;
        }
        else{
            image[sr][sc] = color;
        }
        dfs(image, sr+1, sc, color, initial);
        dfs(image, sr-1, sc, color, initial);
        dfs(image, sr, sc+1, color, initial);
        dfs(image, sr, sc-1, color, initial);
    }
};
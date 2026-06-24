class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        unordered_set<int> seen;
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0; i<n; i++){
            if(!seen.contains(i)) {
                count++;
                dfs(seen, adj, i);
            }
        }
        return count;

    }
    void dfs(unordered_set<int>& seen, vector<vector<int>>& adj, int i){
        if(seen.contains(i)) return;
        seen.insert(i);
        for(int j=0; j<adj[i].size();j++){
            dfs(seen, adj, adj[i][j]);
        }
    }
};

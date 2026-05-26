class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>> adj(n);
        vector<bool> visited(n, 0);
        for(vector<int>& x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        if (!dfs(adj, visited, 0, -1)) return false;
        for (bool v : visited) {
    if (!v) return false;
}

return true;

    }
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int i, int parent){
        visited[i] = true;
        for(int x=0; x<adj[i].size(); x++){
int neighbor = adj[i][x];

if (neighbor == parent) {
    continue;
}

if (visited[neighbor]) {
    return false;
}

if (!dfs(adj, visited, neighbor, i)) {
    return false;
}
        ;

    }
    return true;
    }
};

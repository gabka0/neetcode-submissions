class Graph {
private:
unordered_map<int, unordered_set<int>> adj_list;
bool hasPathBFS(int src, int dst){
    unordered_set<int> visited;
    queue<int> queue;
    queue.push(src);
    while(queue.size()){
        int element = queue.front();
        queue.pop();
        if(element==dst){
            return true;
        }
        for(int dest: adj_list[element]){
            if(visited.count(dest) == 0){
                    visited.insert(dest);
                    queue.push(dest);
            }
        }
    }
    return false;
}
public:
    Graph() {}

    void addEdge(int src, int dst) {
        adj_list[src].insert(dst);
    }

    bool removeEdge(int src, int dst) {
        if (adj_list.find(src) == adj_list.end() || adj_list[src].find(dst) == adj_list[src].end()) {
            return false;
        }
        // Remove the edge
        adj_list[src].erase(dst);
        return true;


    }

    bool hasPath(int src, int dst) {
        return hasPathBFS(src, dst);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* head = new Node(node->val); 
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> cloned;
        cloned[node] = head;
        while(q.size()){
            int length = q.size();
            for(int i=0; i<length;i++){
                Node* cur = q.front();
                q.pop();
                for(auto& neighbor: cur->neighbors){
                        if (cloned.find(neighbor) == cloned.end()) {
        cloned[neighbor] = new Node(neighbor->val);
        q.push(neighbor);
    }
    // Link the clone of 'cur' to the clone of 'neighbor'
    cloned[cur]->neighbors.push_back(cloned[neighbor]);
                }
            }
        }
        return head;
        
    }
};

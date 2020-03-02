// 图节点拷贝
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

// DFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (copiedGraph.count(node) == 0) {
            copiedGraph[node] = new Node(node->val);
            for(auto neighbour : node->neighbors) {
                copiedGraph[node]->neighbors.push_back(cloneGraph(neighbour));
            }
        }
        return copiedGraph[node];
    }
private:
    unordered_map<Node*, Node*> copiedGraph;
};

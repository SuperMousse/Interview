// 图节点拷贝
// DFS或者BFS都能解决问题, 但是需要hash map来避免节点的重复拷贝
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

// BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node* copiedHead = new Node(node->val);
        copiedGraph[node] = copiedHead;
        queue<Node*> queueNode;
        queueNode.push(node);
        while (!queueNode.empty()) {
            Node* pNode = queueNode.front();
            queueNode.pop();
            for (auto neighbour : pNode->neighbors) {
                if (copiedGraph.count(neighbour) == 0) {
                    copiedGraph[neighbour] = new Node(neighbour->val);
                    queueNode.push(neighbour);
                }
                copiedGraph[pNode]->neighbors.push_back(copiedGraph[neighbour]);
            }
        }
        return copiedHead;
    }
private:
    unordered_map<Node*, Node*> copiedGraph;
};

// 课程安排

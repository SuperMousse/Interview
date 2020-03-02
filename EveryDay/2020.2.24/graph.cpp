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
// 检测是否存在入度为0的节点, 如果有入度为0的节点则可能完成,
// 如果不存在入度为0的节点的话说明一定有环, 课程无法完成
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> Graph = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(Graph);
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; ++j) {
                // 存在入度为0的节点, 有可能完成
                if (!degrees[j]) {
                    break;
                }
            }
            // 所有节点(不算已经置为-1的节点)的入度都不为0, 必有环, 无法完成
            if (j == numCourses) {
                return false;
            }
            // 对于找到的入度为0的节点, -1后其入度变为-1, 并将其出度节点入度-1
            --degrees[j];
            for (int v : Graph[j]) {
                --degrees[v];
            }

        }
        return true;
    }
private:
    vector<vector<int>> buildGraph(int numCourses,
                                   vector<vector<int>>& prerequisites) {
        vector<vector<int>> Graph(numCourses,vector<int>());
        for (auto edge : prerequisites) {
            // 认为second是先导课程, second->first
            Graph[edge[1]].push_back(edge[0]);
        }
        return Graph;
    }
    
    vector<int> computeIndegrees(vector<vector<int>>& Graph) {
        vector<int> degrees(Graph.size(), 0);
        for (auto neighbours : Graph) {
            for (int v : neighbours) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};

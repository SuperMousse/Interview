// 需要找到一个仅有出度的节点作为最开始的起点(其入度为0), 然后再向后计算, 找到下一个入度为0的节点

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
            // 所有节点的入度都不为0, 必有环, 无法完成
            if (j == numCourses) {
                return false;
            }
            // 对于找到的入度为0的节点, -1后其入度变为-1, 并将其邻域节点入度-1
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

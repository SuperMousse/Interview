// 返回能够完成的课程编号, 如[0, 1, 2, 3]
// 拓扑排序, 返回的结果就是拓扑排序的结果

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> Graph = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(Graph);
        vector<int> result;
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; ++j) {
                // 存在入度为0的节点, 有可能完成
                if (!degrees[j]) {
                    result.push_back(j);
                    break;
                }
            }
            // 所有节点的入度都不为0, 必有环, 全部无法完成, 返回空的result
            if (j == numCourses) {
                return vector<int>();
            }
            // 对于找到的入度为0的节点, -1后其入度变为-1, 并将其邻域节点入度-1
            --degrees[j];
            for (int v : Graph[j]) {
                --degrees[v];
            }

        }
        return result;
    }
private:
    vector<vector<int>> buildGraph(int numCourses,
                                   vector<vector<int>>& prerequisites) {
        vector<vector<int>> Graph(numCourses,vector<int>());
        for (auto edge : prerequisites) {
            // 认为second是先导课程, second->first, 先导课程为出边
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

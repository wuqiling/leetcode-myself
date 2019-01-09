#include <vector>

using std::pair;
using std::vector;

class Solution {
   public:
    // dfs
    // time = space = O(V+E)~O(V^2) //vertex+edge
    // Runtime: 12 ms, faster than 87.01%
    vector<int> findOrder(int numCourses,
                          vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 0) return {};
        vector<vector<int>> graph(numCourses);
        for (const auto& p : prerequisites)
            graph[p.first].push_back(p.second);  // second->first

        // 0:unknown 1:visiting 2:visited
        vector<int> status(numCourses, 0);
        vector<int> res;

        for (int i = 0; i < numCourses; ++i)
            if (dfs(i, status, graph, res)) return {};

        return res;
    }

   private:
    bool dfs(int cur, vector<int>& status, const vector<vector<int>>& graph,
             vector<int>& res) {
        if (status[cur] == 1) return true;
        if (status[cur] == 2) return false;

        status[cur] = 1;
        for (const auto &g:graph[cur])
            if (dfs(g, status, graph, res)) return true;

        status[cur] = 2;
        res.push_back(cur);
        return false;
    }
};

int main() {
    vector<pair<int, int>> prerequisites{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    Solution s;

    vector<int> ans = s.findOrder(4, prerequisites);
    return 0;
}
#include <iostream>
#include <map>
#include <vector>

using std::multimap;
using std::pair;
using std::vector;

class Solution {
   public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const auto &p : prerequisites) {
            graph[p.first].push_back(p.second);  // first -> second
        }

        // status 0:unknow 1:visting 2:visited
        vector<int> courseStatus(numCourses, 0);

        // dfs
        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, courseStatus, graph)) return false;
        }
        return true;
    }

    //深度优先搜索
    // true:有环
    // false:无环
    bool dfs(int current, vector<int> &courseStatus,
             const vector<vector<int>> &graph) {
        if (courseStatus[current] == 1) return true;   //环
        if (courseStatus[current] == 2) return false;  //无环
        courseStatus[current] = 1;
        for (const auto it = graph[current].begin(); it != graph[current].end();
             it++) {
            if (dfs(*it, courseStatus, graph)) return true;
        }
        courseStatus[current] = 2;
        return false;
    }

    bool canFinish_map(int numCourses, vector<pair<int, int>> &prerequisites) {
        multimap<int, int> graph;
        for (const auto &p : prerequisites) {
            graph.insert(std::make_pair(p.first, p.second));  // first -> second
        }

        // status 0:unknow 1:visting 2:visited
        vector<int> courseStatus(numCourses, 0);

        // dfs
        for (int i = 0; i < numCourses; i++) {
            if (dfs_map(i, courseStatus, graph)) return false;
        }
        return true;
    }

    //深度优先搜索
    // true:有环
    // false:无环
    bool dfs_map(int current, vector<int> &courseStatus,
                 multimap<int, int> &graph) {
        if (courseStatus[current] == 1) return true;   //环
        if (courseStatus[current] == 2) return false;  //无环
        courseStatus[current] = 1;
        multimap<int, int>::iterator it = graph.find(current);
        for (int entries = graph.count(current); entries > 0; entries--) {
            if (dfs_map(it->second, courseStatus, graph)) return true;
            it++;
        }
        courseStatus[current] = 2;
        return false;
    }
};
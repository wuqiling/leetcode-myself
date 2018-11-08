#include <iostream>
#include <queue>
#include <vector>

using std::pair;
using std::queue;
using std::vector;

class Solution {
 public:
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses);
    for (const auto &p : prerequisites) {
      graph[p.second].push_back(p.first);  // second -> first
      inDegree[p.first]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
      if (inDegree[i] == 0) q.push(i);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      numCourses--;
      for (const auto &d : graph[v]) {
        inDegree[d]--;
        if (inDegree[d] == 0) q.push(d);
      }
    }
    return numCourses == 0;
  }
};

int main() {
  Solution a;
  vector<pair<int, int>> pre = {{1, 0}};
  a.canFinish(2, pre);
  return 0;
}
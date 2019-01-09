#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using std::multiset;  // Bst
using std::pair;
using std::priority_queue;
using std::vector;

// Bst£¨multiset£©
// Time O(NlogN) sapce O(N)
// Runtime: 16 ms, faster than 92.38%
class Solution {
   public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        typedef pair<int, int> Event;
        // envet x,h
        vector<Event> es;
        hs.clear();

        // O(N)
        for (const auto &b : buildings) {
            es.emplace_back(b[0], b[2]);
            es.emplace_back(b[1], -b[2]);
        }

        // O(NlogN)
		// comp:
        // The value returned indicates whether the element passed as first
        // argument is considered to go before the second in the specific strict
        // weak ordering it defines.
        sort(es.begin(), es.end(), [](const Event &e1, const Event &e2) {
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });

        vector<pair<int, int>> ans;

        // Process all the evnets
        for (const auto &e : es) {
            int x = e.first;
            bool entering = e.second > 0;
            int h = abs(e.second);

            if (entering) {
                if (h > this->maxHeight()) ans.emplace_back(x, h);
                hs.insert(h);  // O(logN)
            } else {
                hs.erase(hs.equal_range(h).first);
                if (h > this->maxHeight())
                    ans.emplace_back(x, this->maxHeight());
            }
        }

        return ans;
    }

   private:
    int maxHeight() const {
        if (hs.empty()) return 0;
        return *hs.rbegin();  // O(logN)
    }
    multiset<int> hs;
};
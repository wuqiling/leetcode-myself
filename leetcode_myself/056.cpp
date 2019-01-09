#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::max;
using std::min;
using std::pair;
using std::unordered_map;
using std::unordered_set;
using std::vector;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
   public:
    vector<Interval> merge(vector<Interval>& intervals) {
        return merge_2(intervals);
    }

   public:
    // greedy
    // time O(N^2) space O(N)
    // runtime 12ms 45%
    vector<Interval> merge_1(vector<Interval>& in) {
        const int n = in.size();
        if (n <= 1) return in;
        vector<Interval> res;
        unordered_set<int> idxSet;
        vector<pair<int, int>> l2Idx;
        for (int i = 0; i < n; i++) l2Idx.push_back({in[i].start, i});
        sort(l2Idx.begin(), l2Idx.end());
        // NlgN
        for (int i = 0; i < n; i++) {
            int idx1 = l2Idx[i].second;
            if (idxSet.count(idx1)) continue;
            idxSet.insert(idx1);
            int l = in[idx1].start, r = in[idx1].end;
            for (int j = i + 1; j < n; j++) {
                int idx2 = l2Idx[j].second;
                if (idxSet.count(idx2)) continue;
                int ltmp = in[idx2].start, rtmp = in[idx2].end;
                if (ltmp <= r && rtmp >= l) {
                    idxSet.insert(idx2);
                    l = min(l, ltmp);
                    r = max(r, rtmp);
                }
            }
            res.push_back(Interval(l, r));
        }
        return res;
    }

   private:
    // greedy + in-place
    // time O(NlgN) space O(1)
	// runtime 8ms 99%
    vector<Interval> merge_2(vector<Interval>& in) {
        const int n = in.size();
        if (n <= 1) return in;
        vector<Interval> res;
        // lambda
        sort(in.begin(), in.end(),
             [](Interval a, Interval b) { return a.start < b.start; });
        res.push_back(in[0]);
        for (int i = 0; i < n; i++) {
            if (res.back().end < in[i].start)
                res.push_back(in[i]);
            else  // back.end >= in[i].start
                res.back().end = max(res.back().end, in[i].end);
        }
        return res;
    }
};

int main() {
    vector<Interval> intervals{{4, 5}, {1, 4}, {0, 1}};

    Solution s;
    vector<Interval> ans = s.merge(intervals);
    return 0;
}
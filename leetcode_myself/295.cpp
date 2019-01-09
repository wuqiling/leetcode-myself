#include <functional>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

// 2 heap
// time add O(logN) find O(1) space O(N)
// Runtime: 100 ms, faster than 91.61%
class MedianFinder {
   public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (l.empty() || num < l.top())
            l.push(num);
        else
            r.push(num);

        if (l.size() < r.size()) {
            l.push(r.top());
            r.pop();
        } else if (l.size() - r.size() == 2) {
            r.push(l.top());
            l.pop();
        }
    }

    double findMedian() {
        if (l.size() > r.size())
            return l.top();
        else
            return 0.5 * (l.top() + r.top());
    }

   private:
    struct myCompare {
        bool operator()(int a, int b) { return a > b; }
    };
    priority_queue<int> l;                          // max-heap
    priority_queue<int, vector<int>, myCompare> r;  // min-heap
};

// balanced binary search tree
//time add O(logN) find O(1) space O(N)
// multiset ???
//Runtime: 108 ms, faster than 67.07%
class MedianFinder_2 {
   public:
    /** initialize your data structure here. */
    MedianFinder_2() : l(m.cend()), r(m.cend()) {}

    // O(logN)
    void addNum(int num) {
        if (m.empty()) {
            l = r = m.insert(num);
            return;
        }
        m.insert(num);
        if (m.size() & 1) {
            // odd
            if (num >= *r)
                l = r;
            else
                l = --r;
        } else {
            // even
            if (num >= *r)
                ++r;
            else
                --l;
        }
    }

    double findMedian() { return 0.5 * (*l + *r); }

   private:
    multiset<int> m;
    multiset<int>::const_iterator l;  // left median
    multiset<int>::const_iterator r;  // right median
};
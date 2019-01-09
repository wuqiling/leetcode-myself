#include <stack>
#include <vector>

using std::stack;
using std::vector;
class NestedInteger {
   public:
    // Return true if this NestedInteger holds a single integer, rather than a
    // nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer The result is undefined if this NestedInteger holds a
    // nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list The result is undefined if this NestedInteger holds a single
    // integer
    const vector<NestedInteger> &getList() const;
};

//Runtime: 20 ms, faster than 34.00%
class NestedIterator {
   public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); it++)
            nodes.push(*it);
    }

    int next() {
        int res = nodes.top().getInteger();
        nodes.pop();
        return res;
    }

    bool hasNext() {
        while (!nodes.empty()) {
            NestedInteger curr = nodes.top();
            if (curr.isInteger()) return true;
            // cur is list
            nodes.pop();
			const vector<NestedInteger> &adjs = curr.getList();
            for (auto it = adjs.rbegin(); it != adjs.rend(); it++)
                nodes.push(*it);
        }
        return false;
    }

   private:
    stack<NestedInteger> nodes;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
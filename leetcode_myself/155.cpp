#include <algorithm>
#include <stack>
using std::min;
using std::stack;

// Runtime: 16 ms, faster than 99.45%
class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        if (minVal.empty() || x <= getMin()) minVal.push(x);
        data.push(x);
    }

    void pop() {
        if (data.empty()) return;
        if (data.top() == minVal.top()) minVal.pop();
        data.pop();
    }

    int top() {
        if (data.empty()) return INT_MAX;
        return data.top();
    }

    int getMin() {
        if (minVal.empty()) return INT_MAX;
        return minVal.top();
    }

   private:
    stack<int> data;
    stack<int> minVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
    MinStack obj;
    obj.push(1);
    obj.push(2);
    obj.push(0);
    obj.push(-1);
    obj.push(11);
    obj.push(12);
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    int param_3 = obj.top();
    int param_4 = obj.getMin();
    return 0;
}
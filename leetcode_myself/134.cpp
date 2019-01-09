#include <algorithm>
#include <vector>

using std::vector;

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        return canCompleteCircuit_2(gas, cost);
    }

   private:
    // brute force
    // time O(N^2) space O(N)
    // Runtime: 292 ms, faster than 2.16%
    int canCompleteCircuit_1(vector<int>& gas, vector<int>& cost) {
        vector<std::pair<int, int>> remain;
        int sz = gas.size(), cnt0 = 0;
        for (int i = 0; i < sz; ++i) {
            if (gas[i] > cost[i])
                remain.push_back({gas[i] - cost[i], i});
            else if (gas[i] == cost[i])
                cnt0++;
        }
        if (cnt0 == sz) return 0;
        sort(remain.begin(), remain.end());
        for (auto it = remain.rbegin(); it != remain.rend(); it++) {
            int r = 0, cnt = 0;
            for (int i = it->second; cnt < sz; cnt++, i = (i + 1) % sz) {
                if ((r = r + gas[i] - cost[i]) < 0) break;
            }
            if (cnt == sz) return it->second;
        }
        return -1;
    }

    // greedy
    // time O(N) space O(1)
    // Runtime: 4 ms, faster than 99.68%
    int canCompleteCircuit_2(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int res = -1, remain = 0, preRes = -1;
        for (int i = 0; i < n; ++i) {
            if (preRes == i) break;
            if (res == -1 && gas[i] >= cost[i]) res = i;
            if (res != -1) remain = remain + gas[i] - cost[i];
            if (remain < 0) {
                res = -1;
                remain = 0;
            }
            if (i == n - 1 && res != -1 && preRes == -1) {
                i = -1;
                preRes = res;
            }
        }
        return res;
    }
};

int main() {
    vector<int> gas{1};
    vector<int> cost{1};
    int ans = Solution{}.canCompleteCircuit(gas, cost);
    return 0;
}
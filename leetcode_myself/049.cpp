#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {}

   private:
    // time N*M*lgM space N*M
    // runtime 16ms 99%
    vector<vector<string>> groupAnagrams_1(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> sortStrs(strs);
        unordered_map<string, vector<int>> strMap;
        // N*M*lgM
        for (int i = 0; i < strs.size(); i++) {
            sort(sortStrs[i].begin(), sortStrs[i].end());
            strMap[sortStrs[i]].push_back(i);
        }
        for (const auto& m : strMap) {
            vector<string> tmp;
            for (const auto& idx : m.second) tmp.push_back(strs[idx]);
            res.push_back(tmp);
        }
        return res;
    }

    // time N*M space N*M
    // runtime 16ms 99%
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int PRIMES[] = {2,  3,  5,  7,  11, 13, 17, 19,  23,
                              29, 31, 37, 41, 43, 47, 53, 59,  61,
                              67, 71, 73, 79, 83, 89, 97, 101, 107};
        vector<vector<string>> res;
        unordered_map<int64_t, vector<int>> strsMap;
        for (int i = 0; i < strs.size(); i++) {
            int64_t h = 1;
            for (const auto& s : strs[i]) {
                h *= PRIMES[s - 'a'];
            }
            strsMap[h].push_back(i);
        }
        for (const auto& m : strsMap) {
            vector<string> tmp;
            for (const auto& idx : m.second) tmp.push_back(strs[idx]);
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> ans = s.groupAnagrams(strs);
    return 0;
}
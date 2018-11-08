#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);//dont use scanf and printf after this
    std::cin.tie(nullptr);//cin will flush if cout is used while cin is tied to cout
    return nullptr;
}();

class RandomizedSet {
   public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        if (datahash.count(val)) return false;
        datahash[val] = mem.size();
        mem.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        if (!datahash.count(val)) return false;
        int index = datahash[val];
        datahash[mem.back()] = index;
        std::swap(mem[index], mem.back());
        datahash.erase(val);
        mem.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % mem.size();
        return mem[index];
    }

   private:
    unordered_map<int, int> datahash;  // key:num ,value:index  insert/delete
    vector<int> mem;                   // random get
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
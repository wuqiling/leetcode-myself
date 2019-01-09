#include <list>
#include <unordered_map>
#include <vector>

using std::list;
using std::pair;
using std::unordered_map;
using std::vector;

// time O(1) space O(N)
// Runtime: 84 ms, faster than 55.27%
class LRUCache {
   public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        const auto it = map_.find(key);
        if (it == map_.end()) return -1;
        // move this key to the front of the list
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        const auto it = map_.find(key);
        if (it != map_.end()) {
            // update the val
            it->second->second = value;
            // move this key to the front of the list
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        // remove the oldest
        if (cache_.size() == capacity_) {
            map_.erase(cache_.back().first);
            cache_.pop_back();
        }

        // insert the entry into list
        cache_.emplace_front(key, value);
        map_[key] = cache_.begin();
    }

   private:
    int capacity_;
    list<pair<int, int>> cache_;
    // key-key -> val-list iterater
    unordered_map<int, list<pair<int, int>>::iterator> map_;
};

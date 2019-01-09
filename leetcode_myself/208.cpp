#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

// brute force
// Runtime: 140 ms, faster than 2.93%
class Trie {
   public:
    /** Initialize your data structure here. */
    Trie() {}

    // time O(N) space O(N^2)
    /** Inserts a word into the trie. */
    void insert(string word) {
        stringSet_.insert(word);
        for (int i = 0; i < word.size(); ++i)
            prefix_.insert(word.substr(0, i + 1));
    }

    /** Returns if the word is in the trie. */
    bool search(string word) { return stringSet_.count(word); }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) { return prefix_.count(prefix); }

   private:
    unordered_set<string> prefix_;
    unordered_set<string> stringSet_;
};

// at most 26 child per node
// time O(L) space O(n*l^2)
// Runtime: 56 ms, faster than 69.67%
class Trie_2 {
   public:
    /** Initialize your data structure here. */
    Trie_2() : root_(new TrieNode()) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root_.get();
        for (const auto &c : word) {
            if (!p->children[c - 'a']) p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        const TrieNode *p = find(word);
        return p && p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) { return find(prefix) != NULL; }

   private:
    struct TrieNode {
        TrieNode() : is_word(false), children(26, NULL) {}
        ~TrieNode() {
            for (TrieNode *child : children)
                if (child) delete child;
        }
        bool is_word;
        vector<TrieNode *> children;
    };

    const TrieNode *find(const string &prefix) const {
        const TrieNode *p = root_.get();
        for (const auto &c : prefix) {
            p = p->children[c - 'a'];
            if (p == NULL) break;
        }
        return p;
    }
    std::unique_ptr<TrieNode> root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
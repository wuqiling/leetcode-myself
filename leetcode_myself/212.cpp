#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

// dfs + trie
// Runtime: 56 ms, faster than 46.00%
class Solution {
   public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words) {
        TrieNode *head = buildTrie(words);
        _rows = board.size(), _cols = board[0].size();
        vector<string> res;
        for (int row = 0; row < _rows; ++row)
            for (int col = 0; col < _cols; ++col)
                dfs(board, row, col, head, res);
        return res;
    }

   private:
    struct TrieNode {
        TrieNode() : word(""), next(26, NULL) {}
        ~TrieNode() {
            for (TrieNode *n : next)
                if (n) delete n;
        }
        string word;
        vector<TrieNode *> next;
    };

    TrieNode *buildTrie(const vector<string> &words) {
        _root.reset(new TrieNode());
        TrieNode *head = _root.get(), *p = NULL;
        for (const auto &w : words) {
            p = head;
            for (const auto &c : w) {
                if (!p->next[c - 'a']) p->next[c - 'a'] = new TrieNode();
                p = p->next[c - 'a'];
            }
            p->word = w;
        }
        return head;
    }

    void dfs(vector<vector<char>> &board, int row, int col, TrieNode *p,
             vector<string> &res) {
        char ch = board[row][col];
        if (ch == '*' || !p->next[ch - 'a']) return;
        p = p->next[ch - 'a'];
        if (!(p->word).empty()) {
            res.push_back(p->word);
            p->word = "";
        }
        board[row][col] = '*';
        if (col > 0) dfs(board, row, col - 1, p, res);
        if (col + 1 < _cols) dfs(board, row, col + 1, p, res);
        if (row > 0) dfs(board, row - 1, col, p, res);
        if (row + 1 < _rows) dfs(board, row + 1, col, p, res);
        board[row][col] = ch;
    }

   private:
    int _rows;
    int _cols;
    std::unique_ptr<TrieNode> _root;
};

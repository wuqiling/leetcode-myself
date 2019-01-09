#include <sstream>
#include <string>

using std::istringstream;
using std::ostringstream;
using std::string;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// binarize
// time O(N) space O(N)
// Runtime: 24 ms, faster than 62.06%
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

   private:
    enum STATUS { ROOT_NULL = 0x00, ROOT = 0x01, LEFT = 0x02, RIGHT = 0x04 };
    void serialize(TreeNode* root, ostringstream& out) {
        char status = 0;
        if (root) status |= ROOT;
        if (root && root->left) status |= LEFT;
        if (root && root->right) status |= RIGHT;
        out.write(&status, sizeof(status));
        if (!root) return;
        out.write(reinterpret_cast<char*>(&root->val), sizeof(root->val));
        if (status & LEFT) serialize(root->left, out);
        if (status & RIGHT) serialize(root->right, out);
    }

    TreeNode* deserialize(istringstream& in) {
        char status;
        in.read(&status, sizeof(status));
        if (!(status & ROOT)) return NULL;
        auto root = new TreeNode(0);
        in.read(reinterpret_cast<char*>(&root->val), sizeof(root->val));

        root->left = (status & LEFT) ? deserialize(in) : NULL;
        root->right = (status & RIGHT) ? deserialize(in) : NULL;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    TreeNode root[] = {1, 2, 3, 4, 5};
    root[0].left = &root[1];
    root[0].right = &root[2];
    root[2].left = &root[3];
    root[3].left = &root[4];

    Codec c;
    TreeNode* ans = c.deserialize(c.serialize(root));
    return 0;
}
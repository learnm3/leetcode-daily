// LeetCode 102. 二叉树的层序遍历
// 思路：BFS + 队列；每轮先 sz = q.size() 拍快照，for 只处理本层。O(n) 时间 / O(n) 空间
// 易错：q.size() 循环中动态变化，必须提前存 sz
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();               // ★ 本层节点数（先拍快照）
            vector<int> level;
            for (int i = 0; i < sz; ++i) {   // 只处理本层
                TreeNode* cur = q.front(); q.pop();
                level.push_back(cur->val);
                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

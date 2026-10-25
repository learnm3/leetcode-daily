// LeetCode 48. 旋转图像（顺时针 90°）
// 思路：先转置（沿主对角线），再每行反转。O(n²) 时间 / O(1) 空间
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 1. 转置：matrix[i][j] <-> matrix[j][i]
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)   // 只交换上三角，避免换两遍
                swap(matrix[i][j], matrix[j][i]);
        // 2. 每行反转
        for (int i = 0; i < n; ++i)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

// LeetCode 62. 不同路径
// 思路：dp[i][j] = 上方 + 左方；第一行/列全 1；滚动数组压空间。O(mn) 时间 / O(n) 空间
// 易错：内层循环从 j=1 开始，否则 dp[-1] 越界（UBSan）
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);              // 滚动数组，先表示第一行（全 1）
        for (int i = 1; i < m; ++i)        // 从第二行开始逐行填
            for (int j = 1; j < n; ++j)
                dp[j] += dp[j - 1];        // dp[j] = 上方（旧）+ 左方（新 dp[j-1]）
        return dp[n - 1];                  // 最后一格 = 答案
    }
};

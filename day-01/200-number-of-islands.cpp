// LeetCode 200. 岛屿数量
// 思路：遍历网格，遇到 '1' 计数并 DFS 淹没整片岛。O(mn) 时间 / O(mn) 空间（最坏栈深）
// 易错：DFS 边界行用 m、列用 n（j >= n），混用会在长方形网格漏岛或越界（UB）
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return cnt;
    }

private:
    void dfs(vector<vector<char>>& g, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != '1') return; // 行 m、列 n
        g[i][j] = '0';                     // 淹没
        dfs(g, i + 1, j, m, n);
        dfs(g, i - 1, j, m, n);
        dfs(g, i, j + 1, m, n);
        dfs(g, i, j - 1, m, n);
    }
};

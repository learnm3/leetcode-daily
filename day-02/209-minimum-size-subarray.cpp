// LeetCode 209. 长度最小的子数组
// 思路：滑动窗口——右指针扩张，和 ≥ target 时左指针收缩并记录最短。O(n) 时间 / O(1) 空间
// 前提：数组全为正数（单调性）；无解返回 0
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0, ans = INT_MAX;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];                  // 右指针：扩张窗口
            while (sum >= target) {              // 满足条件就收缩
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;         // 全程没达标 → 0
    }
};

// LeetCode 215. 数组中的第 K 个最大元素
// 思路：小顶堆只留 k 个最大的，堆顶 = "前 k 名门槛"。O(n log k) 时间 / O(k) 空间
// 易错：小顶堆 = priority_queue<int, vector<int>, greater<int>>；size_t 与 int 比较前强转
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;  // 小顶堆
        for (int x : nums) {
            pq.push(x);
            if ((int)pq.size() > k) pq.pop();   // 超员踢掉堆顶（当前最小）
        }
        return pq.top();                        // 堆顶 = 第 k 大
    }
};

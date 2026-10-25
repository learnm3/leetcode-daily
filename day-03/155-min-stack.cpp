// LeetCode 155. 最小栈
// 思路：主栈 st + 同步最小值栈 minSt（第 i 层 = st 前 i+1 个元素的最小值）。
// push/pop/top/getMin 全 O(1) 时间；空间 O(n)
// 易错：push 用 <=（重复最小值都记录）；pop 仅当 st.top()==minSt.top() 才同步弹
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;      // 主栈
    stack<int> minSt;   // 辅助栈：记录"到当前高度为止的最小值"
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);  // 新低（或重复最小值）入
        else minSt.push(minSt.top());                              // 最小值没变，复制当前最小
    }

    void pop() {
        if (st.top() == minSt.top()) minSt.pop();  // 弹出的恰是当前最小值 → 同步弹
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minSt.top(); }           // O(1) 取最小
};

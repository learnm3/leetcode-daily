// LeetCode 146. LRU 缓存
// 思路：哈希表（O(1) 定位）+ 双向链表（O(1) 搬头/删尾）。
// 链表头 = 最近使用，链表尾 = 最久未使用；虚拟头尾哨兵避免空链表特判。
// 易错：构造函数必须初始化 cap（漏了是 UB）；pop 尾部要同步 erase 哈希并 delete。
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    unordered_map<int, Node*> mp;
    Node* head;   // 虚拟头：head->next 是最近使用
    Node* tail;   // 虚拟尾：tail->prev 是最久未使用
    int cap;

    void remove(Node* node) {               // 从链表摘出节点
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertHead(Node* node) {           // 插到头部（最近使用）
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : cap(capacity) {   // ★ 必须初始化 cap
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        remove(node);
        insertHead(node);                     // 访问 = 最近使用，搬到头部
        return node->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {                  // 已存在：更新值并搬到头部
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insertHead(node);
            return;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        insertHead(node);
        if (mp.size() > static_cast<size_t>(cap)) {  // 超容量：删最久未使用
            Node* last = tail->prev;
            remove(last);
            mp.erase(last->key);
            delete last;
        }
    }
};

#include "../header.h"

class test0313 {
    struct Node {
        Node *le, *ri;
        int key, val;
        Node(int _key, int _val) {
            key = _key, val = _val;
            le = ri = nullptr;
        }
    }*L, *R;

    int capacity;
    unordered_map<int, Node*> h;

    test0313(int cap) {
        capacity = cap;
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->ri = R;
        R->le = L;
    }

    void insert(Node* p) {
        p->ri = L->ri;
        p->ri->le = p;
        L->ri = p;
        p->le = L;
    }

    void del(Node* p) {
        p->le->ri = p->ri;
        p->ri->le = p->le;
        p->le = p->ri = nullptr;

    }

    int get(int key) {
        if(h.count(key)) {  // key 存在，则返回val，并放到链表首部
            auto p = h[key];
            del(p);
            insert(p);
            return p->val;
        } else {    // key 不存在
            return -1;
        }
    }

    void put(int key, int val) {
        if(h.count(key)) {  // key存在，更新 val，放到链表首部
            auto p = h[key];
            p->val = val;
            del(p);
            insert(p);
        } else {    // key 不存在，判断是否满了，若没满头插入链表
            if(h.size() == capacity) {
                // 满了，删除最久未使用的节点(最右边节点)
                auto delNode = R->le;
                auto delKey = delNode->val;
                del(delNode);
                h.erase(delKey);
                delete delNode;
            }
            // 首插
            Node* p = new Node(key, val);
            insert(p);
            h[key] = p;
        }
    }

};
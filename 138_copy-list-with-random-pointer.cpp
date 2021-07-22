//
// Created by 71401 on 2021/7/22.
//
#include <unordered_map>


// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
private:
    unordered_map<Node *, Node *> map;
public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        if (!map.count(head)) {
            Node *newNode = new Node(head->val);
            map[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);

        }

        return map[head];
    }
};
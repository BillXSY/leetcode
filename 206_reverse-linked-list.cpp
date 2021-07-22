//
// Created by 71401 on 2021/7/22.
//

#include <vector>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
class Solution {
private:
    vector<int> stack;
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *n = head;
        while (n) {
            stack.push_back(n->val);
            n = n->next;
        }

        ListNode *hd = new ListNode(-1);
        auto h = hd;
        while (stack.size()) {
            h->next = new ListNode(stack[stack.size() - 1]);
            stack.pop_back();
            h = h->next;
        }
        return hd->next;
    }
};*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
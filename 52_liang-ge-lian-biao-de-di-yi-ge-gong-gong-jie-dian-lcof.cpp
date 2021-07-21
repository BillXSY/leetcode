//
// Created by 71401 on 2021/7/21.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode *a = HeadA;
        ListNode *b = HeadB;
        while (a != b) {
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }
        return a;
    }
};
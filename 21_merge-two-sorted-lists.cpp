//
// Created by 71401 on 2021/7/23.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *prevHead = new ListNode(-1);
        ListNode *prev = prevHead;
        while (l1 || l2) {
            int num1 = !l1 ? 1000 : l1->val;
            int num2 = !l2 ? 1000 : l2->val;
            if (num1 < num2) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        return prevHead->next;

    }
};
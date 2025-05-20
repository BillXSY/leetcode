//
// Created by 71401 on 2021/7/20.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        int carry = 0;
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        while (l1 || l2 || carry) {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int bit = num1 + num2 + carry;
            carry = bit / 10;
            bit = bit % 10;

            curr->next = new ListNode(bit);

            curr = curr->next;

            if (l1) l1 = l1->next;

            if (l2) l2 = l2->next;
        }
        return head->next
    }
};
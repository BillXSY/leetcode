//
// Created by 71401 on 2021/7/29.
//

#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // def a struct Status
    struct Status {
        int val;
        ListNode *ptr;
        // reload operator<
        bool operator<(const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // push all the beginning nodes into the priority_queue
        for (auto node: lists) {
            if (node) {
                q.push({node->val, node});
            }
        }
        ListNode head, *tail = &head;
        // while priority_queue is not empty
        // pop the node with smallest value
        // and push its next* into the queue
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;


    }
};
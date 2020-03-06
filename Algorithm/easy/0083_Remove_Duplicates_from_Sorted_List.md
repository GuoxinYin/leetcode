Description
--
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example
--
1. Input: 1->1->2, Output: 1->2

2. Input: 1->1->2->3->3, Output: 1->2->3

cpp solutions 
---
```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *left = head;
        ListNode *right = head -> next;
        while (right!= nullptr) {
            if (right->val == left->val) {
                right = right->next;
            } else {
                left->next = right;
                left = right;
                right = right -> next;
            }
        }
        if (left->next!=nullptr) left->next = nullptr;
        return head;
    }
};
```


Some Ideas
--
Another way is to only have one pointer and update that pointer on each step.
1. if `pointer->val == pointer->next->val`, then `pointer->next = pointer->next->next`.
2. else, `pointer = pointer->next`.

Keep the above `if` statement in `while(pointer && pointer->next)`, i.e. we must ensure that both are not `nullptr`.

Note that in the method, since we update out pointer on every step, we don't need to check after we finish the `while` loop.

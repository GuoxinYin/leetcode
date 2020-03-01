Description
--
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example
--
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

cpp solutions
--
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        ListNode *l3 = nullptr;
        if (l1->val <= l2->val) {
            l3 = l1;
            l1 = l1->next;
        } else {
            l3 = l2;
            l2 = l2->next;
        }
        ListNode *end = l3;
        while (true) {
            if (l1 == nullptr) {
                end->next = l2;
                break;
            } else if (l2 == nullptr) {
                end->next = l1;
                break;
            }
            if (l1->val <= l2->val) {
                end->next = l1;
                end = l1;
                l1 = l1->next;
            } else {
                end->next = l2;
                end = l2;
                l2 = l2->next;
            }
        }
        return l3;
    }
};
```

Some Ideas
--
1. That's a tricky problem. It takes me a while to figure out the input and output. The input is a string like "[1,2,4]" and so does the output, which should be "[1,1,2,3,4,4]". It actually has other functions to turn the string into a pointer to the ListNode and we should not worry about it.
2. In the beginning, I test my problem in Clion and it occurs a very weird problem. I acually created a new ListNode object in every step and it seems to take a lot of space and finally weird things happened: When I create a new ListNode object, it takes the address of the `l3` pointer, which is the thing that I need to return!
3. Therefore, instead of creating new objects, I just reuse the 'l1' and 'l2' pointer, which turns out to be the right way to solve the problem.


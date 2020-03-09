Description
--

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Example
--

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```

cpp solutions
---

#### My attempt using unordered_set, needs O(n) space and O(n) time

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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while (head) {
            if (s.find(head)!=s.end()) return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};
```

#### [Faster and Slower Runner](https://leetcode.com/problems/linked-list-cycle/discuss/44604/My-faster-and-slower-runner-solution) from Discussion

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
 use faster and lower runner solution. (2 pointers)
 the faster one move 2 steps, and slower one move only one step.
 if there's a circle, the faster one will finally "catch" the slower one. 
 (the distance between these 2 pointers will decrease one every time.)
 
 if there's no circle, the faster runner will reach the end of linked list. (NULL)
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)    
            return false;
 
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
                return true;
        }
 
        return false;
    }
};
```

#### [Dog Pee Method](https://leetcode.com/problems/linked-list-cycle/discuss/44485/Simple-and-easy-understanding-java-solution-Time-o(n)-Space-O(1)), after visit one node, change its next to *head*

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
    	ListNode p = head,pre = head;
    	while(p != null && p.next != null){
    		if (p.next == head) return true;
    		p = p.next;
    		pre.next = head;
    		pre = p;
    	}
        return false;
    }
}
```



Some Ideas
--
I love the last method.
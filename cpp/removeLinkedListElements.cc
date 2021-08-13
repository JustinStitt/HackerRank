// link = https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode* p = nullptr, *c;
        c = head;
        
        /* step through list and check equivalence */
        while(c) {
            if(c->val == val) {
                ListNode* _next = c->next;
                if(c == head) head = _next;
                delete c;
                c = _next;
                if(p) p->next = c;
                continue;
            }
            p = c;
            c = c->next;
        } // end while
        
        return head;
    }
};

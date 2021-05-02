/**
 * link = https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* p = head, *n = head->next;
        while(n){
            if(p->val == n->val){
                p->next = n->next;
                delete n;
                n = p->next;
            }else{
                p = p->next;
                n = p->next;    
            }
        }
        return head;
    }
};


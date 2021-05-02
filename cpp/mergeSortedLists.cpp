/**
 * link = https://leetcode.com/problems/merge-two-sorted-lists
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
    int listComp(ListNode* lhs, ListNode* rhs){
        // 0 if lhs is <=, 1 if rhs smaller <, 2 if both
        if(!lhs && !rhs) return 2;
        if(!lhs && rhs) return 0;
        if(lhs && !rhs) return 1;
        return (lhs->val <= rhs->val ? 1 : 0);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        if(listComp(l1, l2) == 2) return head;
        if(listComp(l1, l2)) { head = l1; l1=l1->next; }
        else{ head = l2; l2 = l2->next; }
        ListNode* trav = head;
        
        while(listComp(l1, l2) != 2){ // while both are not nullptr
            bool lt = listComp(l1, l2);
            trav->next = (lt ? l1 : l2);
            trav = trav->next;
            if(lt) l1 = l1->next;
            else l2   = l2->next;
        }
        return head;
    }
};

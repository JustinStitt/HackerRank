// link = https://leetcode.com/problems/delete-node-in-a-linked-list
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
    void deleteNode(ListNode* node) {
        
        node->val = node->next->val;
        
        if(!node->next->next) {
            delete node->next;
            node->next = nullptr;
            return;
        }
        
        
        deleteNode(node->next);
    }
};

/* better O(1) soln.
 *void deleteNode(ListNode* node) {
        ListNode* _next = node->next;
        *node = *_next;
        delete _next;
    }
 *
 * */

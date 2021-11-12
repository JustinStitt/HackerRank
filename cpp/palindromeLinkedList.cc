// link = https://leetcode.com/problems/palindrome-linked-list/
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
    
    void isPalindrome(ListNode*& head, ListNode* curr, int& p) {
        // get curr to end of list
        if(curr->next)
            isPalindrome(head, curr->next, p);
        
        // check curr against head
        if(head->val != curr->val && p == 2) { // can't be palindrome
            p = 0;
            return;
        }
        
        if(head == curr && p == 2) {
            p = 1;
            return;
        }
        if(head->next != curr && p == 2)
            head = head->next;
    }
    
    bool isPalindrome(ListNode* head) {
        int p = 2;
        isPalindrome(head, head, p);
        return p;
    }
};


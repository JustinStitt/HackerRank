public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret_head = nullptr, *ret_tail = nullptr;
        
        while (1) {
            /* keep track of the smallest list */
            ListNode** small = nullptr;
            
            for(auto&& list : lists) {
                if (!list) continue; // don't even consider null (empty) lists
                int to_compare = (small ? (*small)->val : INT_MAX);
                if (list->val > to_compare) continue; // don't consider larger case
                small = &list; // we found a new smaller list! point to its address (of its ptr)
            }
            
            /* if we made it through the above for loop with no hits, we've exhausted all lists */
            if (!small) return ret_head;
            
            /* we can now create a new node based on small and add to ret_head (or ret_tail) */
            ListNode* to_add = new ListNode((*small)->val, nullptr);
            if (!ret_head) { // our list is empty
                ret_head = to_add;
                ret_tail = ret_head;
            } else { // not empty
                ret_tail->next = to_add;
                ret_tail = ret_tail->next;
            }
            
            /* now that we've used a node from small, advance its indirective to next */
            (*small) = (*small)->next;
        }
        
        return nullptr; // we shouldn't get here...
    }
};

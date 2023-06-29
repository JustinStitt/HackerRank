/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode *swapPairs(struct ListNode *head) {
  if (head == NULL || head->next == NULL)
    return head;

  ListNode *u = head;
  ListNode *v = head;

  while (v->next) {
    v = u->next;
    if (v == NULL)
      break;
    int tmp = u->val;
    u->val = v->val;
    v->val = tmp;

    u = v->next;
  }

  return head;
}

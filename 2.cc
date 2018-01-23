#include <stdlib.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *res = NULL, **tail = &res;
    int c = 0;

    while (l1 && l2) {
      ListNode *node;
      int t = l1->val + l2->val + c;

      l1 = l1->next;
      l2 = l2->next;
      c = 0;
      if (t > 9) {
        t -= 10;
        c = 1;
      }
      node = new ListNode(t);
      *tail = node;
      tail = &node->next;
    }

    while (l1) {
      ListNode *node;
      int t = l1->val + c;

      l1 = l1->next;
      c = 0;
      if (t > 9) {
        t -= 10;
        c = 1;
      }
      node = new ListNode(t);
      *tail = node;
      tail = &node->next;
    }

    while (l2) {
      ListNode *node;
      int t = l2->val + c;

      l2 = l2->next;
      c = 0;
      if (t > 9) {
        t -= 10;
        c = 1;
      }
      node = new ListNode(t);
      *tail = node;
      tail = &node->next;
    }

    if (c) {
      ListNode *node = new ListNode(c);
      *tail = node;
      tail = &node->next;
    }

    return(res);
  }
};

int main(void){}

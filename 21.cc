struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = 0, **prevp = &head;

        while (l1 && l2) {
            ListNode *p;
            if (l1->val < l2->val) {
                p = l1;
                l1 = l1->next;
            } else {
                p = l2;
                l2 = l2->next;
            }
            p->next = 0;
            *prevp = p;
            prevp = &p->next;
        }
        if (l1)
            *prevp = l1;
        else if (l2)
            *prevp = l2;
        return(head);
    }
};

int main(void){}

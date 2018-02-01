struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return(head);

        ListNode **prevp, *p;

        for (p = head; n > 1; --n)
            p = p->next;
        for (prevp = &head; p->next; p = p->next)
            prevp = &(*prevp)->next;
        p = *prevp;
        *prevp = p->next;
        delete p;
        return(head);
    }
};

int main(void){}

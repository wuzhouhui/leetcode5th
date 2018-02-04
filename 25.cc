struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *newhead = 0, **tail = &newhead, *p, *next, *savedp, *t;
        int i;

        while (head) {
            for (p = head, i = 1; i <= k && head; i++)
                head = head->next;
            if (i <= k) {
                *tail = p;
                break;
            }

            savedp = p;
            next = 0;
            while (--i > 0) {
                t = p;
                p = p->next;
                t->next = next;
                next = t;
            }
            *tail = next;
            tail = &savedp->next;
        }
        return(newhead);
    }
};

int main(void){}

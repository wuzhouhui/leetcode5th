struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution {
  public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *newhead = 0, **tail = &newhead;
        while (head) {
            ListNode *p1 = head, *p2;
            head = head->next;
            if (head) {
                p2 = head;
                head = head->next;
                *tail = p2;
                tail = &p2->next;
                *tail = p1;
                tail = &p1->next;
            } else {
                *tail = p1;
                tail = &p1->next;
                break;
            }
        }
        *tail = 0;
        return(newhead);
    }
};

int main(void){}

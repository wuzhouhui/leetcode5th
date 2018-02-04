#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return(do_merge(lists, 0, lists.size()));
    }

  private:
    ListNode *do_merge(vector<ListNode *> &lists, int start, int len)
    {
        if (len == 0)
            return(0);
        if (len == 1)
            return(lists[start]);

        ListNode *head = 0, **prevp = &head;
        ListNode *l1 = do_merge(lists, start, len / 2);
        ListNode *l2 = do_merge(lists, start + len / 2, len - len / 2);

        while (l1 && l2) {
            ListNode *t;
            if (l1->val < l2->val) {
                t = l1;
                l1 = l1->next;
            } else {
                t = l2;
                l2 = l2->next;
            }
            t->next = 0;
            *prevp = t;
            prevp = &t->next;
        }

        if (l1)
            *prevp = l1;
        else if (l2)
            *prevp = l2;
        return(head);
    }
};

int main(void)
{
}

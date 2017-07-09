struct ListNode {
	int val;
	struct ListNode *next;
};

static struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *new, **tail = &new;
	struct ListNode *t;

	while (l1 && l2) {
		if (l1->val < l2->val) {
			t = l1;
			l1 = l1->next;
		} else {
			t = l2;
			l2 = l2->next;
		}
		*tail = t;
		tail = &t->next;
	}
	while (l1) {
		t = l1;
		l1 = l1->next;
		*tail = t;
		tail = &t->next;
	}
	while (l2) {
		t = l2;
		l2 = l2->next;
		*tail = t;
		tail = &t->next;
	}
	*tail = 0;
	return(new);
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	if (listsSize <= 0)
		return(0);
	if (listsSize == 1)
		return(lists[0]);
	int t = listsSize / 2;
	struct ListNode *l1 = mergeKLists(lists, t);
	struct ListNode *l2 = mergeKLists(lists + t, listsSize - t);
	return(mergeTwoLists(l1, l2));
}

main(){}

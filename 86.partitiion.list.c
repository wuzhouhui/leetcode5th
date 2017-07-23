struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x)
{
	struct ListNode *lt, *ge;
	struct ListNode **lttail = &lt, **getail = &ge;

	while (head) {
		struct ListNode *t = head;
		head = head->next;
		if (t->val < x) {
			*lttail = t;
			lttail = &t->next;
		} else {
			*getail = t;
			getail = &t->next;
		}
	}
	*getail = 0;
	*lttail = ge;
	return(lt);
}
main(){}

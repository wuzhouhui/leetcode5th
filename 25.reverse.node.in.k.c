struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	struct ListNode *new, **tail = &new;

	while (head) {
		int i = 0;
		struct ListNode *revhead = 0;
		struct ListNode *ptail, *t;

		while (head && i < k) {
			t = head;
			head = head->next;
			t->next = revhead;
			revhead = t;
			if (i++ == 0)
				ptail = t;
		}

		if (i < k) {
			while (revhead) {
				t = revhead;
				revhead = revhead->next;
				t->next = head;
				head = t;
			}
			*tail = head;
			return(new);
		}

		*tail = revhead;
		tail = &ptail->next;
	}

	*tail = 0;
	return(new);
}

main(){}

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
	struct ListNode *new, **tail = &new;
	struct ListNode *p1, *p2;

	while (head) {
		p1 = head; head = head->next;
		if (head == 0) {
			*tail = p1;
			tail = &p1->next;
			break;
		}
		p2 = head; head = head->next;
		*tail = p2; tail = &p2->next;
		*tail = p1; tail = &p1->next;
	}
	*tail = 0;
	return(new);
}
main(){}

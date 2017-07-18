struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
	int	i, c;
	struct ListNode *new, *p1, *p2;

	for (p1 = head, c = 0; p1; p1 = p1->next)
		c++;
	if (c == 0 || (k %= c) == 0)
		return(head);
	for (i = 1, p1 = head; i < c - k; i++)
		p1 = p1->next;
	new = p2 = p1->next;
	p1->next = 0;
	while (p2->next)
		p2 = p2->next;
	p2->next = head;
	return(new);
}
main(){}

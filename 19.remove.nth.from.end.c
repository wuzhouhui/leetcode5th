#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	struct ListNode *p1, *p2;
	int	i;

	for (p2 = head, i = 1; i <= n; i++)
		p2 = p2->next;
	if (p2 == NULL) {
		p2 = head;
		head = head->next;
		free(p2);
		return(head);
	}
	for (p1 = head; p2->next;) {
		p1 = p1->next;
		p2 = p2->next;
	}
	p2 = p1->next;
	p1->next = p2->next;
	free(p2);
	return(head);
}

main(){}

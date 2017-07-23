#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	struct ListNode *new, **tail = &new;
	struct ListNode *prev = NULL;

	while (head) {
		struct ListNode *t = head;
		head = head->next;
		if (prev == NULL || prev->val != t->val) {
			prev = t;
			*tail = t;
			tail = &t->next;
		} else {
			free(t);
		}
	}
	*tail = NULL;
	return(new);
}
main(){}

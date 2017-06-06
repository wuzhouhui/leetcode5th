#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *res = NULL;
	struct ListNode **tail = &res;
	int	c = 0;

	while (l1 && l2) {
		int t = l1->val + l2->val + c;
		c = 0;
		l1 = l1->next;
		l2 = l2->next;
		if (t > 9) {
			t -= 10;
			c = 1;
		}
		struct ListNode *new = malloc(sizeof(*new));
		new->val = t;
		*tail = new;
		tail = &new->next;
	}

	while (l1) {
		int t = l1->val + c;
		c = 0;
		l1 = l1->next;
		if (t > 9) {
			t -= 10;
			c = 1;
		}
		struct ListNode *new = malloc(sizeof(*new));
		new->val = t;
		*tail = new;
		tail = &new->next;
	}

	while (l2) {
		int t = l2->val + c;
		c = 0;
		l2 = l2->next;
		if (t > 9) {
			t -= 10;
			c = 1;
		}
		struct ListNode *new = malloc(sizeof(*new));
		new->val = t;
		*tail = new;
		tail = &new->next;
	}

	if (c) {
		struct ListNode *new = malloc(sizeof(*new));
		new->val = 1;
		*tail = new;
		tail = &new->next;
	}

	*tail = NULL;
	return(res);
}

main(){}

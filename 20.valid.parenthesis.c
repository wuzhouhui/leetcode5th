#include <stdlib.h>

#ifndef bool
#define bool int
#endif

struct stack {
	char val;
	struct stack *next;
};

static char pop(struct stack **head)
{
	if (*head == NULL)
		return(0);
	struct stack *t = *head;
	char v = t->val;
	*head = (*head)->next;
	free(t);
	return(v);
}

static void push(struct stack **head, char v)
{
	struct stack *t = calloc(1, sizeof(*t));
	t->val = v;
	t->next = *head;
	*head = t;
}

bool isValid(char *s)
{
	struct stack *head = NULL;

	while (*s) {
		switch (*s) {
		case '(':
		case '[':
		case '{':
			push(&head, *s++);
			break;
		case ')':
			if (pop(&head) != '(')
				return(0);
			s++;
			break;
		case ']':
			if (pop(&head) != '[')
				return(0);
			s++;
			break;
		case '}':
			if (pop(&head) != '{')
				return(0);
			s++;
			break;
		}
	}
	return(head == NULL);
}

main(){}

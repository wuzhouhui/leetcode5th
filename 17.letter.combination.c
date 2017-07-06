#include <string.h>
#include <stdlib.h>

static char **res, buffer[512];
static int maxp, p;
static char *board[] = {
	"", "", "abc",
	"def", "ghi", "jkl",
	"mno", "pqrs", "tuv",
	"wxyz",
};
static char buffer[512];

static void addans(void)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = strdup(buffer);
}

static void do_comb(char *digits, char *buf)
{
	int i;

	if (*digits == 0) {
		*buf = 0;
		if (strlen(buffer) > 0)
			addans();
		return;
	}

	for (i = 0; board[*digits - '0'][i]; i++) {
		*buf = board[*digits - '0'][i];
		do_comb(digits + 1, buf + 1);
	}
	if (i == 0)
		do_comb(digits + 1, buf);
}

char **letterCombinations(char *digits, int *returnSize)
{
	res = NULL;
	maxp = p = 0;
	do_comb(digits, buffer);
	*returnSize = p;
	return(res);
}
main()
{
	int n;
	char **res = letterCombinations("012", &n);
}

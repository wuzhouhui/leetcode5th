#include <string.h>

static int cmpfun(const void *a , const void *b)
{
	char **stra = (char **)a;
	char **strb = (char **)b;
	return(strcmp(*stra, *strb));
}

static int commlen(const char *str1, const char *str2)
{
	int n = 0;
	while (*str1 && *str2 && *str1 == *str2)
		n++, str1++, str2++;
	return(n);
}

char *longestCommonPrefix(char **strs, int strsSize)
{
	if (strsSize <= 0)
		return(strdup(""));
	if (strsSize == 1)
		return(strdup(strs[0]));

	int min = -1, i;

	qsort(strs, strsSize, sizeof(strs[0]), cmpfun);

	for (i = 1; i < strsSize; i++) {
		int t = commlen(strs[i - 1], strs[i]);
		if (min < 0)
			min = t;
		else if (t < min)
			min = t;
	}

	if (min == 0)
		return(strdup(""));
	else
		return(strndup(strs[0], min));
}

main(){}

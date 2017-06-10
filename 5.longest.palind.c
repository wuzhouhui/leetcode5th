#include <stdlib.h>
#include <string.h>

char *longestPalindrome(char *s)
{
	int start = 0, length = 0;
	int i, j, k;
	int slen = strlen(s);

	for (i = 0; i < slen; i++) {
		for (j = k = i; j >= 0 && k < slen; j--, k++)
			if (s[j] != s[k])
				break;
		int t = (--k) - (++j) + 1;
		if (t > length) {
			start = j;
			length = t;
		}

		for (j = i, k = i + 1; j >= 0 && k < slen; j--, k++)
			if (s[j] != s[k])
				break;
		t = (--k) - (++j) + 1;
		if (t > length) {
			start = j;
			length = t;
		}
	}

	return(strndup(s + start, length));
}

int main(int argc, char *argv[])
{
}

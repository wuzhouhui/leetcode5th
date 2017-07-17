#include <string.h>

int lengthOfLastWord(char *s)
{
	int i, end;

	for (i = strlen(s) - 1; i >= 0 && s[i] == ' '; i--)
		;
	end = i;
	for (; i >= 0 && s[i] != ' '; i--)
		;
	return(end - i);
}
main(){}

int strStr(char *haystack, char *needle)
{
	int	i, j;

	if (haystack[0] == 0 && needle[0] == 0)
		return(0);
	if (haystack[0] == 0)
		return(-1);
	if (needle[0] == 0)
		return(0);
	for (i = 0; haystack[i]; i++) {
		for (j = 0; haystack[j + i] && haystack[j + i] == needle[j];
				j++)
			;
		if (needle[j] == 0)
			return(i);
	}
	return(-1);
}
main(){}

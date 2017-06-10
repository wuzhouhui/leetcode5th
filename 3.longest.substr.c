#include <string.h>

int lengthOfLongestSubstring(char *s)
{
	int cnt[256] = { 0, };
	int left = 0, right = 0;
	int len = strlen(s);
	int res = 0;

	while (right < len) {
		while (right < len && ++cnt[s[right]] <= 1)
			right++;

		int t = right - left;
		if (t >= res)
			res = t;

		if (right >= len)
			break;

		while (--cnt[s[left++]] == 0)
			;
		right++;
	}

	return(res);
}

int main(int argc, char *argv[])
{
}

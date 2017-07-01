#ifndef bool
#define bool int
#endif

bool isPalindrome(int x)
{
	if (x == 0)
		return(1);
	if (x < 0 || x % 10 == 0)
		return(0);
	int rev = 0;
	while (x > rev) {
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	return(x == rev || x == rev / 10);
}

main(){}

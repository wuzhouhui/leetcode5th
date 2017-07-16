static double do_pow(double x, long int n)
{
	if (n == 0)
		return(1);
	if (n == 1)
		return(x);
	if (n % 2)
		return(x * do_pow(x, n - 1));
	double t = do_pow(x, n / 2);
	return(t * t);
}

double myPow(double x, int n)
{
	long int ln = n;

	if (ln < 0) {
		ln = -ln;
		return(1 / do_pow(x, ln));
	} else
		return(do_pow(x, ln));
}
main(){}

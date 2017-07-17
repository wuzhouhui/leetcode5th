int maxSubArray(int *nums, int numsSize)
{
	int max, curmax, i;

	max = curmax = nums[0];
	for (i = 1; i < numsSize; i++) {
		int t = curmax + nums[i];
		if (nums[i] > t)
			curmax = nums[i];
		else
			curmax = t;
		if (curmax > max)
			max = curmax;
	}
	return(max);
}
main(){}

static void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int firstMissingPositive(int *nums, int numsSize)
{
	if (numsSize < 1)
		return(1);
	int i = 0;
	while (i < numsSize) {
		while (nums[i] >= 1 && nums[i] <= numsSize &&
				nums[i] != i + 1 &&
				nums[nums[i] - 1] != nums[i])
			swap(&nums[i], &nums[nums[i] - 1]);
		i++;
	}
	for (i = 0; i < numsSize; i++)
		if (nums[i] != i + 1)
			return(i + 1);
	return(numsSize + 1);
}
main(){}

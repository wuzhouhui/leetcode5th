int removeDuplicates(int *nums, int numsSize)
{
	if (numsSize < 2)
		return(numsSize);
	int i, j;
	for (i = 0, j = 1; j < numsSize; j++)
		if (nums[j] == nums[i])
			continue;
		else
			nums[++i] = nums[j];
	return(++i);
}
main(){}

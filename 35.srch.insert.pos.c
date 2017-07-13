int searchInsert(int *nums, int numsSize, int target)
{
	int left = -1, right = numsSize;
	while (left + 1 != right) {
		int mid = (left + right) / 2;
		if (nums[mid] < target)
			left = mid;
		else
			right = mid;
	}
	if (right < numsSize)
		return(right);
	if (right == numsSize)
		return(numsSize);
	return(0);
}
main(){}

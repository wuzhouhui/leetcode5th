#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int left, right;
	int *res = malloc(sizeof(*res) << 1);

	res[0] = -1;
	res[1] = -1;
	*returnSize = 2;

	left = -1;
	right = numsSize;
	while (left + 1 != right) {
		int m = (left + right) / 2;
		if (nums[m] <= target)
			left = m;
		else
			right = m;
	}
	if (left < 0 || nums[left] != target)
		return(res);
	res[1] = left;

	left = -1;
	right = numsSize;
	while (left + 1 != right) {
		int m = (left + right) / 2;
		if (nums[m] < target)
			left = m;
		else
			right = m;
	}
	res[0] = right;

	return(res);
}

main(){}

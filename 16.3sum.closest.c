#include <stdlib.h>

static int cmpfun(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return(-1);
	else if (*(int *)a > *(int *)b)
		return(1);
	return(0);
}

int threeSumClosest(int *nums, int numsSize, int target)
{
	long int min = -1;
	long int res;
	int i;

	qsort(nums, numsSize, sizeof(*nums), cmpfun);
	for (i = 0; i < numsSize - 2; i++) {
		int j = i + 1, k = numsSize - 1;
		while (j < k) {
			long int t = nums[i] + nums[j] + nums[k];
			long int d;
			if (t < target) {
				d = target - t;
				j++;
			} else if (t > target) {
				d = t- target;
				k--;
			} else
				return(t);

			if (min < 0 || d < min) {
				min = d;
				res = t;
			}
		}
	}

	return(res);
}

main()
{
	int a[] = { 0, 1, 2, };
	return(threeSumClosest(a, 3, 0));
}

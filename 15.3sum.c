#include <stdlib.h>

static int **res, p, maxp;

static addans(int a, int b , int c)
{
	int i;

	for (i = 0; i < p; i++) {
		if (res[i][0] == a && res[i][1] == b && res[i][2] == c)
			return;
	}

	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p] = malloc(sizeof(**res) * 3);
	res[p][0] = a;
	res[p][1] = b;
	res[p][2] = c;
	p++;
}

static int cmpfun(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return(-1);
	else if (*(int *)a > *(int *)b)
		return(1);
	return(0);
}

int **threeSum(int *nums, int numsSize, int *returnSize)
{
	int i;

	res = NULL;
	p = maxp = 0;
	qsort(nums, numsSize, sizeof(*nums), cmpfun);
	for (i = 0; i < numsSize - 2; i++) {
		int j = i + 1, k = numsSize - 1;
		while (j < k) {
			int t = nums[i] + nums[j] + nums[k];
			if (t == 0) {
				addans(nums[i], nums[j], nums[k]);
				j++;
			} else if (t > 0)
				k--;
			else
				j++;
		}
	}

	*returnSize = p;
	return(res);
}

main(){}

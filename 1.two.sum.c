#include <stdlib.h>

struct tstruct {
	int val;
	int idx;
};

static int cmpfun(const void *a, const void *b)
{
	const struct tstruct *ta = a;
	const struct tstruct *tb = b;
	if (ta->val < tb->val)
		return(-1);
	else if (ta->val > tb->val)
		return(1);
	return(0);
}

int *twoSum(int *nums, int numsSize, int target)
{
	struct tstruct vi[numsSize];
	int i, j, *res = malloc(sizeof(*res) << 1);

	for (i = 0; i < numsSize; i++) {
		vi[i].val = nums[i];
		vi[i].idx = i;
	}

	qsort(vi, numsSize, sizeof(vi[0]), cmpfun);
	for (i = 0, j = numsSize - 1; i < j; ) {
		int t = vi[i].val + vi[j].val;
		if (t == target) {
			res[0] = vi[i].idx;
			res[1] = vi[j].idx;
			break;
		}
		if (t < target)
			i++;
		else
			j--;
	}

	return(res);
}

main(){}

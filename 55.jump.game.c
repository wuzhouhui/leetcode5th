#ifndef bool
#define bool int
#endif

bool canJump(int *nums, int numsSize)
{
	int i, cur, next, maxstep;

	if (numsSize <= 1)
		return(1);
	cur = 0;
	while (1) {
		maxstep = 0;
		for (i = 1; i <= nums[cur]; i++) {
			int t = cur + i;
			if (t >= numsSize - 1)
				return(1);
			t = i + nums[cur + i];
			if (t >= numsSize - 1)
				return(1);
			if (t > maxstep) {
				maxstep = t;
				next = cur + i;
			}
		}
		if (maxstep == 0)
			return(0);
		cur = next;
	}
}
main(){}

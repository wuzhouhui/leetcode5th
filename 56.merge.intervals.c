#include <stdlib.h>
#include <string.h>

struct Interval {
	int start;
	int end;
};

static struct Interval *res;
static int p, maxp;

static int cmpfun(const void *a, const void *b)
{
	const struct Interval *ai = a;
	const struct Interval *bi = b;
	if (ai->start < bi->start)
		return(-1);
	if (ai->start > bi->start)
		return(1);
	if (ai->end < bi->end)
		return(-1);
	if (ai->end > bi->end)
		return(1);
	return(0);
}

static void addans(const struct Interval *i)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	memcpy(&res[p++], i, sizeof(*i));
}

struct Interval *merge(struct Interval *intervals, int intervalsSize,
		int *returnSize)
{
	int i;

	res = 0;
	p = maxp = 0;
	qsort(intervals, intervalsSize, sizeof(*intervals), cmpfun);
	for (i = 0; i < intervalsSize; ) {
		struct Interval itv = intervals[i++];
		while (i < intervalsSize && intervals[i].start <=
				itv.end) {
			if (intervals[i].end > itv.end)
				itv.end = intervals[i].end;
			i++;
		}
		addans(&itv);
	}
	*returnSize = p;
	return(res);
}
main()
{
	struct Interval i[] = {
		{ 1, 3, },
		{ 2, 6, },
		{ 8, 10 },
		{ 15, 18},
	};
	int n;
	merge(i, sizeof(i) / sizeof(i[0]), &n);
}

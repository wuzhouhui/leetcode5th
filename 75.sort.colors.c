enum {
	RED = 0,
	WHITE,
	BLUE,

	COLOR_NR,
};

void sortColors(int *nums, int numsSize)
{
	int color[COLOR_NR] = { 0 }, i;

	for (i = 0; i < numsSize; i++)
		color[nums[i]]++;

	i = 0;
	while (color[RED]--)
		nums[i++] = RED;
	while (color[WHITE]--)
		nums[i++] = WHITE;
	while (color[BLUE]--)
		nums[i++] = BLUE;
}
main(){}

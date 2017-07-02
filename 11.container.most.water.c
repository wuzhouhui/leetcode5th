int maxArea(int *height, int heightSize)
{
	int res = 0, i = 0, j = heightSize - 1;
	while (i < j) {
		if (height[i] < height[j]) {
			heightSize = height[i] * (j - i);
			i++;
		} else {
			heightSize = height[j] * (j - i);
			j--;
		}
		if (heightSize > res)
			res = heightSize;
	}
	return(res);
}
main(){}

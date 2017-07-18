int uniquePaths(int m, int n)
{
	int path[100][100];
	int i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (i && j)
				path[i][j] = path[i - 1][j] + path[i][j - 1];
			else if (!i && j)
				path[i][j] = path[i][j - 1];
			else if (i && !j)
				path[i][j] = path[i - 1][j];
			else
				path[i][j] = 1;
		}
	}
	return(path[m - 1][n - 1]);
}
main(){}

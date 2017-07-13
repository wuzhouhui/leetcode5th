#include <string.h>

#ifndef bool
#define bool int
#endif

bool isValidSudoku(char **board, int i, int j)
{
	int cnt[10];
	int m, n;

	for (i = 0; i < 9; i++) {
		memset(cnt, 0, sizeof(cnt));
		for (j = 0; j < 9; j++) {
			if (board[i][j] == '.')
				continue;
			if (++cnt[board[i][j] - '0'] > 1)
				return(0);
		}
	}

	for (j = 0; j < 9; j++) {
		memset(cnt, 0, sizeof(cnt));
		for (i = 0; i < 9; i++) {
			if (board[i][j] == '.')
				continue;
			if (++cnt[board[i][j] - '0'] > 1)
				return(0);
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			memset(cnt, 0, sizeof(cnt));
			for (m = i * 3; m < i * 3 + 3; m++) {
				for (n = j * 3; n < j * 3 + 3; n++) {
					if (board[m][n] == '.')
						continue;
					if (++cnt[board[m][n] - '0'] > 1)
						return(0);
				}
			}
		}
	}

	return(1);
}
main(){}

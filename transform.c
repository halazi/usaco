/*
ID: wx53821
LANG: C
TASK: transform
*/

#include <stdio.h>

#define N 10

int cmp90(char before[][N+1], char after[][N+1], int n)
{
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (before[i][j] != after[j][n-1-i]) {
				return 0;
			}
		}
	}
	return 1;
}

int cmp180(char before[][N+1], char after[][N+1], int n)
{
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (before[i][j] != after[n-1-i][n-1-j]) {
				return 0;
			}
		}
	}
	return 1;
}

int cmp270(char before[][N+1], char after[][N+1], int n)
{
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (before[i][j] != after[n-1-j][i]) {
				return 0;
			}
		}
	}
	return 1;
}

int cmpRef(char before[][N+1], char after[][N+1], int n)
{
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (before[i][j] != after[i][n-1-j]) {
				return 0;
			}
		}
	}
	return 1;
}

int cmpCom(char before[][N+1], char after[][N+1], int n)
{
	int i, j;
	int flag[3] = {1, 1, 1};
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (flag[0]) {
				if (before[i][j] != after[n-1-j][n-1-i]) {
					flag[0] = 0;
				}
			}
			if (flag[1]) {
				if (before[i][j] != after[n-1-i][j]) {
					flag[1] = 0;
				}
			}
			if (flag[2]) {
				if (before[i][j] != after[j][i]) {
					flag[2] = 0;
				}
			}
			if (flag[0] == 0 && flag[1] == 0 && flag[2] == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int cmpSame(char before[][N+1], char after[][N+1], int n)
{
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (before[i][j] != after[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

main () {
    FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");
	int n;
    fscanf (fin, "%d", &n);
	char before[N][N+1];
	char after[N][N+1];
	int i;
	for (i=0; i<n; i++) {
		fscanf(fin, "%s", before[i]);
	}
	for (i=0; i<n; i++) {
		fscanf(fin, "%s", after[i]);
	}
	fclose(fin);
	if (cmp90(before, after, n)) {
		fprintf(fout, "%d\n", 1);
	} else if (cmp180(before, after, n)) {
		fprintf(fout, "%d\n", 2);
	} else if (cmp270(before, after, n)) {
		fprintf(fout, "%d\n", 3);
	} else if (cmpRef(before, after, n)) {
		fprintf(fout, "%d\n", 4);
	} else if (cmpCom(before, after, n)) {
		fprintf(fout, "%d\n", 5);
	} else if (cmpSame(before, after, n)) {
		fprintf(fout, "%d\n", 6);
	} else {
		fprintf(fout, "%d\n", 7);
	}
	fclose(fout);
    exit (0);
}

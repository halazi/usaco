/*
ID: wx53821
LANG: C
TASK: dualpal
*/

#include <stdio.h>

#define L 18

void convert(int old, int base, char *new, int *d)
{
	int i = 0;
	while (old != 0) {
		int t = old % base;
		new[i] = t <= 9 ? '0' + t : t - 10 + 'A';
		i++;
		old = old / base;
	}
	*d = i;
}

int isPal(char *num, int d)
{
	int i, j;
	i = 0;
	j = d - 1;
	while (i < j) {
		if (num[i] != num[j]) {
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}

main () {
   	FILE *fin  = fopen ("dualpal.in", "r");
   	FILE *fout = fopen ("dualpal.out", "w");
	int n, s;
	fscanf (fin, "%d%d", &n, &s);
	fclose(fin);
	int i;
	char num[32];
	int d;
	int *pd = &d;
	int base;
	int j;
	for (i=s+1, j=0; j<n; i++) {
		int count = 0;
		for (base=10; base>=2; base--) {
			convert(i, base, num, pd);
			if (isPal(num, d)) {
				count++;
				if (count == 2) {
					j++;
					fprintf(fout, "%d\n", i);
					break;
				}
			}
		}
	}
	fclose(fout);
	exit (0);
}

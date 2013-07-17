/*
ID: wx53821
LANG: C
TASK: palsquare
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
   	FILE *fin  = fopen ("palsquare.in", "r");
   	FILE *fout = fopen ("palsquare.out", "w");
	int b;
	fscanf (fin, "%d", &b);
	fclose(fin);
	int i;
	char num[L], original[L/2];
	int d, o;
	int *pd = &d;
	int *po = &o;
	for (i=1; i<=300; i++) {
		convert(i*i, b, num, pd);
		if (isPal(num, d)) {
			int j;
			convert(i, b, original, po);
			for (j=o-1; j>=0; j--) {
				fprintf(fout, "%c", original[j]);
			}
			fprintf(fout, " ");
			for (j=0; j<d; j++) {
				fprintf(fout, "%c", num[j]);
			}
			fprintf(fout, "\n");
		}
	}
	fclose(fout);
    	exit (0);
}

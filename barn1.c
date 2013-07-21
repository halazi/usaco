/*
ID: wx53821
LANG: C
TASK: barn1
*/

#include <stdio.h>

main () {
   	FILE *fin  = fopen ("barn1.in", "r");
   	FILE *fout = fopen ("barn1.out", "w");
	int m, s, c;
	fscanf (fin, "%d%d%d", &m, &s, &c);
	int i;
	char o[201];
	for (i=1; i<=s; i++) {
		o[i] = 0;
	}
	int t;
	for (i=0; i<c; i++) {
		fscanf(fin, "%d", &t);
		o[t] = 1;
	}
	fclose(fin);
	for (i=1; i<=s; i++) {
		if (o[i]) {
			break;
		}
	}
	int start = i;
	for (i=s; i>=0; i--) {
		if (o[i]) {
			break;
		}
	}
	int end = i;
	int result = end - start + 1;
	i = start + 1;
	int current_count = 0;
	int a[50];
	int j;
	while (1) {
		if (i > end) {
			break;
		}
		if (o[i]) {
			i++;
		} else {
			j = i + 1;
			while (!o[j]) {
				j++;
			}
			int current = j - i;
			i = j;
			if (current_count < m - 1) {
				a[current_count] = current;
				int k = current_count;
				for (; k>=1; k--) {
					if (a[k] > a[k-1]) {
						int tmp = a[k];
						a[k] = a[k-1];
						a[k-1] = tmp;
					} else {
						break;
					}
				}
				current_count++;
			} else {
				if (current > a[m-2]) {
					a[m-2] = current;
					int k = m - 2;
					for (; k>=1; k--) {
						if (a[k] > a[k-1]) {
							int tmp = a[k];
							a[k] = a[k-1];
							a[k-1] = tmp;
						} else {
							break;
						}
					}
				}
			}
		}
	}
	for (i=0; i<current_count; i++) {
		result -= a[i];
	}
	fprintf(fout, "%d\n", result);
	fclose(fout);
	exit (0);
}

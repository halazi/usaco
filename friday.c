/*
ID: wx53821
LANG: C
TASK: friday
*/

#include <stdio.h>

main () {
    	FILE *fin  = fopen ("friday.in", "r");
    	FILE *fout = fopen ("friday.out", "w");
	int n;
    	fscanf (fin, "%d", &n);
	fclose(fin);
	int i;
	int count[7] = {0,0,0,0,0,0,0};
	int current = 6;
	for (i=0; i<n; i++) {
		// Jan
		count[current]++;
		current += 31;
		current %= 7;

		// Feb
		count[current]++;
		if (i % 400 == 100) {
			current += 29;
		} else {
			if (i % 100 == 0 || i % 4 != 0) {
				current += 28;
			} else {
				current += 29;
			}
		}
		current %= 7;

		// Mar
		count[current]++;
		current += 31;
		current %= 7;

		// Apr
		count[current]++;
		current += 30;
		current %= 7;

		// May
		count[current]++;
		current += 31;
		current %= 7;

		// June
		count[current]++;
		current += 30;
		current %= 7;

		// July
		count[current]++;
		current += 31;
		current %= 7;

		// Aug
		count[current]++;
		current += 31;
		current %= 7;

		// Sept
		count[current]++;
		current += 30;
		current %= 7;

		// Oct
		count[current]++;
		current += 31;
		current %= 7;

		// Nov
		count[current]++;
		current += 30;
		current %= 7;

		// Dec
		count[current]++;
		current += 31;
		current %= 7;

	}
	fprintf(fout, "%d %d %d %d %d %d %d\n", count[6], count[0], count[1], count[2], count[3], count[4], count[5]);
	fclose(fout);
    	exit (0);
}

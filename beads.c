/*
ID: wx53821
LANG: C
TASK: beads
*/

#include <stdio.h>

#define NEXT(i,n) (i + 1 == n ? 0 : i + 1)
#define PREV(i,n) (i == 0 ? n - 1 : i - 1)

int count(char *bead, int n, int break_pos)
{
	int total = 1;

	int start_back = PREV(break_pos, n);
	int start_forward = break_pos;

	char color_back = bead[start_back];
	char color_forward = bead[start_forward];

	int forward = NEXT(start_forward, n);
	while (bead[forward] == 'w' || color_forward == 'w' || color_forward == bead[forward]) {
		total++;
		if (total >= n) break;
		if (color_forward == 'w') {
			color_forward = bead[forward];
		}
		forward = NEXT(forward, n);
	}
	total++;
	int back = PREV(start_back, n);
	while (bead[back] == 'w' || color_back == 'w' || color_back == bead[back]) {
		total++;
		if (total >= n) break;
		if (color_back == 'w') {
			color_back = bead[back];
		}
		back = PREV(back, n);
	}


	if (total >= n) total = n;

	return total;
}

main () {
    	FILE *fin  = fopen ("beads.in", "r");
    	FILE *fout = fopen ("beads.out", "w");
	int n;
	char bead[351];
	fscanf(fin, "%d", &n);
    	fscanf (fin, "%s", bead);
	fclose(fin);
	int i;
	int max = count(bead, n, 0);
	for (i=1; i<n; i++) {
//		if (bead[i-1] == bead[i]) continue;
		int t = count(bead, n, i);
		if (t > max) max = t;
	}
	fprintf(fout, "%d\n", max);
	fclose(fout);
    	exit (0);
}

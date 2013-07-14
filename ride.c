/*
ID: wx53821
LANG: C
TASK: ride
*/
#include <stdio.h>
main () {
    	FILE *fin  = fopen ("ride.in", "r");
    	FILE *fout = fopen ("ride.out", "w");
    	char comet[6] = {0,0,0,0,0,0};
	char group[6] = {0,0,0,0,0,0};
    	fscanf (fin, "%s%s", comet, group);
	fclose(fin);
	int i;
	char tc, tg;
	int pc = 1; 
	int pg = 1;
	for (i=0; i<6; i++) {
		tc = comet[i] - 'A' + 1;
		tg = group[i] - 'A' + 1;
		if (tc >=1 && tc <=26) {
			pc *= tc;
			pc %= 47;
		}
		if (tg >=1 && tg <=26) {
			pg *= tg;
			pg %= 47;
		}
	}
	if (pc == pg) {
    		fprintf (fout, "GO\n");
	} else {
		fprintf(fout, "STAY\n");
	}
	fclose(fout);
    	exit (0);
}

/*
ID: wx53821
LANG: C
TASK: gift1
*/

#include <stdio.h>

#define N_PEOPLE 10
#define L_NAME 15

int cmp_ok(char *s1, char *s2)
{
	int i = 0;
	while(s1[i] != '\0') {
		if (s1[i] == s2[i]) {
			i++;
		} else {
			return 0;
		}
	}
	if (s2[i] == '\0') return 1;
	else return 0;
}

int name2num(char name_list[][L_NAME], char *name)
{
	int i;
	for (i=0; i<N_PEOPLE; i++) {
		if (cmp_ok(name_list[i], name)) {
			return i;
		}
	}
	return -1;
}

main () {
    	FILE *fin  = fopen ("gift1.in", "r");
    	FILE *fout = fopen ("gift1.out", "w");
	int np;
    	fscanf (fin, "%d", &np);
    	char name[N_PEOPLE][L_NAME];
    	int i;
    	for (i=0; i<np; i++) {
		fscanf(fin, "%s", name[i]);
    	}
    	char snd[L_NAME];
    	int initial_money[N_PEOPLE];
	int money;
    	int n;
    	int deposit[N_PEOPLE] = {0,0,0,0,0,0,0,0,0,0};
    	for (i=0; i<np; i++) {
		fscanf(fin, "%s", snd);
		fscanf(fin, "%d%d", &money, &n);
		int t;
		if ((t = name2num(name, snd)) != -1) {
			initial_money[t] = money;
			if (n != 0) deposit[t] += money % n;
			else deposit[t] += money;
		}
		int j;
		char rcv[L_NAME];
		for (j=0; j<n; j++) {
			fscanf(fin, "%s", rcv);
			if ((t = name2num(name, rcv)) != -1) {
				deposit[t] += money / n;
			}
		}
	}
	fclose(fin);
	for (i=0; i<np; i++) {
		fprintf(fout, "%s %d\n", name[i], deposit[i] - initial_money[i]);
	}
	fclose(fout);
    	exit (0);
}

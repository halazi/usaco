/*
ID: wx53821
LANG: C
TASK: milk
*/

#include <stdio.h>

typedef struct {
	int price;
	long amount;
} Farmer;

void sort(Farmer *f, int m)
{
	if (m == 0) {
		return;
	}
	int i;
	int j;
	for (i=1; i<m; i++) {
		int t = i;
		for (j=i-1; j>=0; j--) {
			if (f[t].price < f[j].price) {
				Farmer tmp = f[t];
				f[t] = f[j];
				f[j] = tmp;
				t = j;
			} else {
				break;
			}
		}
	}
}

main () {
   	FILE *fin  = fopen ("milk.in", "r");
   	FILE *fout = fopen ("milk.out", "w");
	long n;
	int m;
   	fscanf (fin, "%ld%d", &n, &m);
	Farmer f[5000];
	int i;
	for (i=0; i<m; i++) {
		fscanf(fin, "%d%ld", &f[i].price, &f[i].amount);
	}
	sort(f, m);
	i = 0;
	long total = 0;
	while (n > 0) {
		if (f[i].amount <= n) {
			n -= f[i].amount;
			total += f[i].price * f[i].amount;
		} else {
			total += f[i].price * n;
			n = 0;
		}
		i++;
	}
	fprintf(fout, "%ld\n", total);
	fclose(fout);
   	exit (0);
}

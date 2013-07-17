/*
ID: wx53821
LANG: C
TASK: namenum
*/

#include <stdio.h>

main () {
    FILE *fin = fopen("namenum.in", "r");
    FILE *fout = fopen("namenum.out", "w");
	char num[13];
    fscanf (fin, "%s", num);
	fclose(fin);
	char letter[12][2];
	int i;
	for (i=0; num[i]!='\0'; i++) {
		switch (num[i]) {
			case '2':
				letter[i][0] = 'A';
				letter[i][1] = 'C';
				break;
			case '3':
				letter[i][0] = 'D';
				letter[i][1] = 'F';
				break;
			case '4':
				letter[i][0] = 'G';
				letter[i][1] = 'I';
				break;
			case '5':
				letter[i][0] = 'J';
				letter[i][1] = 'L';
				break;
			case '6':
				letter[i][0] = 'M';
				letter[i][1] = 'O';
				break;
			case '7':
				letter[i][0] = 'P';
				letter[i][1] = 'S';
				break;
			case '8':
				letter[i][0] = 'T';
				letter[i][1] = 'V';
				break;
			case '9':
				letter[i][0] = 'W';
				letter[i][1] = 'Y';
				break;
		}
	}
	fin = fopen("dict.txt", "r");
	char dict[5000][13];
	int n = 0;
	while (fscanf(fin, "%s", dict[n]) != EOF) {
		n++;
	}
	fclose(fin);
	int j;
	for (j=0; j<n; j++) {
		int k;
		for (k=0; k<i; k++) {
			if (dict[j][k] < letter[k][0] || dict[j][k] > letter[k][1]) {
				break;
			}
		}
		if (k == i && dict[j][k] == '\0') {
			fprintf(fout, "%s\n", dict[j]);
		}
	}
	if (ftell(fout) == 0) {
		fprintf(fout, "NONE\n");
	}
	fclose(fout);
    exit (0);
}

/*
ID: wx53821
LANG: C
TASK: milk2
*/

#include <stdio.h>

#define N 5000

typedef struct {
	long s;
	long e;
} Time;

int median3(Time *t, int start, int end)
{
	int mid = (start + end) / 2;
	if (t[start].s <= t[mid].s) {
		if (t[start].s >= t[end].s) {
			return start;
		} else {
			if (t[mid].s <= t[end].s) {
				return mid;
			} else {
				return end;
			}
		}
	} else {
		if (t[mid].s >= t[end].s) {
			return mid;
		} else {
			if (t[start].s <= t[end].s) {
				return start;
			} else {
				return end;
			}
		}
	}
}

void swap(Time *t, int a, int b)
{
	Time temp = t[a];
	t[a] = t[b];
	t[b] = temp;
}

void quicksort(Time *t, int start, int end)
{
	if (start + 10 <= end) {
		int pivot = median3(t, start, end);
		if (pivot != end) {
			swap(t, pivot, end);
		}
		long pivot_val = t[end].s;
		int i = start;
		int j = end - 1;
		while (1) {
			while (t[i].s < pivot_val) {
				i++;
			}
			while (t[j].s > pivot_val) {
				j--;
			}
			if (i < j) {
				swap(t, i, j);
				i++;
				j--;
			} else {
				break;
			}
		}
		swap(t, i, end);
		quicksort(t, start, i-1);
		quicksort(t, i+1, end);
	} else {
		if (start == end) {
			return;
		} else {
			int curr = start + 1;
			for (; curr <= end; curr++) {
				int i;
				Time temp = t[curr];
				for (i=curr-1; i>=0; i--) {
					if (temp.s < t[i].s) {
						t[i+1] = t[i];
					} else {
						break;
					}
				}
				t[i+1] = temp;
			}
		}
	}
}

void sort(Time *t, int n)
{
	quicksort(t, 0, n-1);
}

main () {
    	FILE *fin  = fopen ("milk2.in", "r");
    	FILE *fout = fopen ("milk2.out", "w");
	int n;
    	fscanf (fin, "%d", &n);
	int i;
	Time t[N];
	for (i=0; i<n; i++) {
		fscanf(fin, "%ld%ld", &t[i].s, &t[i].e);
	}
	fclose(fin);
	sort(t, n);
	Time period[N];
	i = 0;
	int period_count = 0;
	while (i < n) {
		period[period_count].s = t[i].s;
		int j;
		long max_end = t[i].e;
		for (j=i+1; j<n; j++) {
			if (t[j].s <= max_end) {
				if (max_end < t[j].e) {
					max_end = t[j].e;
				}
			} else {
				break;
			}
		}
		period[period_count].e = max_end;
		i = j;
		period_count++;
	}
	long max_milk = 0;
	for (i=0; i<period_count; i++) {
		if (max_milk < period[i].e - period[i].s) {
			max_milk = period[i].e - period[i].s;
		}
	}
	long max_no_milk = 0;
	for (i=0; i<period_count-1; i++) {
		if (max_no_milk < period[i+1].s - period[i].e) {
			max_no_milk = period[i+1].s - period[i].e;
		}
	}
	fprintf(fout, "%ld %ld\n", max_milk, max_no_milk);
	fclose(fout);
    	exit (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b);
void pyramid(int n, int* mas);
void check(int* mas, int n, int i);
void sort(int n, int* mas);
int main()
{
	clock_t cstart, cend;
	time_t tstart, tend;
	double tT, cT;
	int n;
	int* mas = NULL;
	FILE* fp = NULL;
	FILE* fin = NULL;

	fin = fopen("b.txt", "w");
	fp = fopen("a.txt", "r");
	fscanf(fp, "%d", &n);
	mas = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) if (fscanf(fp, "%d", &mas[i]) != 1) break;
	//for (int i = 0; i < n; i++) printf("%d %d\n", i, mas[i]);
	//printf("\n");
	cstart = clock();
	tstart = time(NULL);
	pyramid(n, mas);
	tend = time(NULL);
	cend = clock();
	tT = difftime(tend, tstart);
	cT = (double)(cend - cstart) / CLOCKS_PER_SEC;
	for (int i = 0; i < n; i++) fprintf(fin, "%d %d\n", i, mas[i]);
	printf("time: %f clock = %lf\n", tT, cT);
	return 0;
}
void pyramid(int n, int* mas)
{
	sort(n, mas);
	while (n > 1)
	{
		swap(&mas[0], &mas[n - 1]);
		n--;
		check(mas, n, 0);
	}
}
void sort(int n, int* mas)
{
	int m = (n - 1) / 2;
	for (int i = m; i >= 0; i--)
	{
		check(mas, n, i);
	}
}
void check(int* mas, int n, int i)
{
		int left = 2 * i + 1, right = 2 * i + 2, max = i;
		if (left < n && mas[left] > mas[max]) max = left;
		if (right < n && mas[right] > mas[max]) max = right;
		if (max != i)
		{
			swap(&mas[max], &mas[i]);
			check(mas, n, max);
		}
}
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int part(int* mas, int i, int j);
void sort(int* mas, int i, int j);
void swap(int* a, int* b);

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
    if (fp == NULL) { printf("file not open\n"); return -1; }
    if (fscanf(fp, "%d", &n) != 1) { printf("n not read\n"); return -2; }
    if (n <= 0) { printf("n<0\n"); return -3; }
    mas = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) if (fscanf(fp, "%d", &mas[i]) != 1)break;

    // for (int i = 0; i < n; i++) printf("%d %d\n", i, mas[i]);
    //printf("\n");
    cstart = clock();
    tstart = time(NULL);
    sort(mas, 0, n - 1);
    tend = time(NULL);
    cend = clock();
    tT = difftime(tend, tstart);
    cT = (double)(cend - cstart) / CLOCKS_PER_SEC;
    for (int i = 0; i < n; i++) fprintf(fin, "%d %d\n", i, mas[i]);
    printf("time: %f clock = %lf\n", tT, cT);
    return 0;
}

void sort(int* mas, int i, int j)
{
    if (i < j)
    {
        int m = part(mas, i, j);
        sort(mas, i, m);
        sort(mas, m + 1, j);
    }
}

int part(int* mas, int i, int j)
{
    int p = mas[(i + j) / 2];
    while (1)
    {
        while (mas[i] < p) i++;
        while (mas[j] > p) j--;
        if (i >= j) return j;
        swap(&mas[i], &mas[j]);
        i++; j--;
    }
}
void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
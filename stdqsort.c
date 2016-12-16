#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(const void*i,const void*j) { return *(int*)i - *(int*)j; }

int main(void) {
	int *arr, *p, *p1; size_t arrsiz; unsigned n;
	srand(time(NULL)); arr=malloc(sizeof(int));

	while (1==scanf("%u", &n)) {
		arrsiz = sizeof(int)*n;	
		arr = realloc(arr, arrsiz);
		for (p=arr, p1=arr+n; p != p1; ++p) *p = rand() % 100;
		qsort(arr, n, sizeof(int), cmp);
		for (p=arr, p1=arr+n; p != p1; ++p) printf("%d ", *p);
		putchar('\n');
		}
	
	free(arr); return 0;
	}

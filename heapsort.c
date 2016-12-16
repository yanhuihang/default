/* Usage: ./a.out arrsiz maxelement
 * The first line is the heap, the second is the sorted array;
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* [0,n) --> [1,n] */
#define TRANSARR(arr) (arr-1)

#define PARENT(x) ((x)>>1)

#define ROOTIFY(x) if (x <= siz && a[x] > a[k]) k = x;

#define SWAP(i,j) *(i) ^= *(j); *(j) ^= *(i); *(i) ^= *(j);

void heapify(int *a, int root, int siz)
	{
	int right, left, k;
hiter:
	left = root<<1; right = left++; k = root;
	ROOTIFY(right); ROOTIFY(left);
	if (k != root) { SWAP(a+root, a+k); root = k; goto hiter; }
	}

int *parr1, *parr2;
#define PARR(a, siz) parr1=a+1; parr2=a+siz+1; for (; parr1 != parr2; ++parr1) \
	printf("%d ", *parr1); putchar('\n');

void heapsort(int *a, int n)
	{
	int p;	
	p=PARENT(n); for (; p; --p) heapify(a,p,n);
	PARR(a, n);
	for (; n != 1; ) { SWAP(a+1,a+n); heapify(a,1,--n); }
	}


#define ARR p1=arr; p2=arr+n; for (; p1 != p2; ++p1) 

int main(int argc, char **argv)
	{
	int *arr, n=10, *p1, *p2, m=100;
	if (argc>=3) sscanf(argv[2], "%d", &m);
	if (argc>=2) sscanf(argv[1], "%d", &n);
	arr = malloc(sizeof(int)*n); srand(time(NULL)); ARR *p1 = rand()%m;
	heapsort(TRANSARR(arr), n); ARR printf("%d ", *p1); putchar('\n'); 
	free(arr); return 0;
	}

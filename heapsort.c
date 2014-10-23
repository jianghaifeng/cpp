#include <stdio.h>

#define PARENT(i) ((i+1)/2 - 1)
#define LEFT(i)   ((i+1)*2 - 1)
#define RIGHT(i)  ((i+1)*2)


void exchange(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void sift_down(int *A, int len, int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;
	
	//find the largest of ternery
	if (l < len && A[i] < A[l])
		largest = l;
	else 
		largest = i;
	
	if (r < len && A[largest] < A[r])
		largest = r;
	
	if (largest != i) 
	{
		exchange(&A[i], &A[largest]);
		sift_down(A, len, largest);
	}
}

void build_max_heap(int *A, int len)
{
	int i=0;
	for (i=(len+1)/2-1; i>=0; i--)
	{
		sift_down(A, len, i);
	}
}

void heap_sort(int *A, int len)
{
	int size = len;
	int i;
	
	build_max_heap(A, len);
	
	for (i=len-1; i>=1; i--)
	{
		exchange(&A[0], &A[i]);
		size -= 1;
		sift_down(A, size, 0);
	}
}

int main()
{
	int a[] = {5,3,7,2,8,6,1,9};
	heap_sort(a, sizeof(a)/sizeof(int));
	
	int i=0;
	for (i=0; i<sizeof(a)/sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}

#include<stdio.h>
int a[100];
int part(int p, int q)
{
	int x, i, j, t1, t2;
	x = a[p];
	i = p;
	j = q;
	while(i<j)
	{
		while(a[i] <= x)
		{
			i++;
		}
		while(a[j] > x)
		{
			j--;
		}
		if(i<j)
		{
			t1 = a[i];
			a[i] = a[j];
			a[j] = t1;
		}
	}
	t2 = a[j];
	a[j] = a[p];
	a[p] = t2;
	return j;
}
int qck_sort(int p, int q)
{
	int r;
	if(p < q)
	{
		r = part(p,q);
		qck_sort(p, r-1);
		qck_sort(r+1, q);
	}
}
int main()
{
	int i, n;
	printf("Enter The Number of Elements to be Inserted: ");
	scanf("%d", &n);
	printf("Enter Array Elements: ");
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Before Sorting: ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", a[i]);
	}
	qck_sort(0, n-1);
	printf("\nAfter Sorting: ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}


//O(nlogn)

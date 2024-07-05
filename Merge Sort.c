#include<stdio.h>
int a[100];
int merge(int low, int mid, int high)
{
	int i, j, k, l, b[20];
	i = low;
	j = mid + 1;
	k = low;
	while(i <= mid && j <= high)
	{
		if(a[i] < a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while(i <= mid)
	{
		b[k++] = a[i++];
	}
	while(j <= high)
	{
		b[k++] = a[j++];
	}
	for(l=low; l<=high; l++)
	{
		a[l] = b[l];
	}
}
int mer_sort(int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high) / 2;
		mer_sort(low, mid);
		mer_sort(mid+1, high);
		merge(low, mid, high);
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
	mer_sort(0, n-1);
	printf("\nAfter Sorting: ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}




//O(nlogn)

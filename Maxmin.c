#include<stdio.h>
int max, min, a[100];
void maxmin(int x, int y)
{
	int max1, min1;
	if(x == y)
	{
		max = a[x];
		min = a[x];
	}
	else if(x == y-1)
	{
		if(a[x] > a[y])
		{
			max = a[x];
			min = a[y];
		}
		else
		{
			max = a[y];
			min = a[x];
		}
	}
	else
	{
		int mid = (x + y) / 2;
		maxmin(x, mid);
		max1 = max;
		min1 = min;
		maxmin(mid+1, y);
		if(max1 > max)
			max = max1;
		if(max1 > max)
			max = max1;
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
	maxmin(0, n-1);
	printf("Minimum Element is %d\n", min);
	printf("Maximum Element is %d\n", max);
	return 0;
}















//O(n)

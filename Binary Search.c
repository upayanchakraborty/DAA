//15
//1 3 4 6 7 8 10 12 13 18 20 22 23 27 29
//search 4
#include<stdio.h>
int a[100], max;
int bin_ser(int lb, int ub, int x)
{
	int mid = (lb + ub) / 2;
	if (lb <= ub)
	{
		if(x == a[mid])
		{
			return mid+1;
		}
		else if(x < a[mid])
		{
			return bin_ser(lb, mid - 1, x);
		}
		else
		{
			return bin_ser(mid + 1, ub, x);
		}
	}
	return -1;
}
int main()
{
	int i, x, r;
	printf("Enter The Number of Elements to be Inserted: ");
	scanf("%d", &max);
	printf("Enter Array Elements: ");
	for(i=0; i<max; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter The Value to be Searched by Binary Search Method: ");
	scanf("%d", &x);
	r = bin_ser(0, max-1, x);
	if(r==-1)
		printf("Value Not Found");
	else
		printf("%d is found at Position %d", x, r);
	return 0;
}

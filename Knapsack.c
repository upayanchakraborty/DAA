#include<stdio.h>
int i, j, u, n;
float p[20], x[20], w[20], r[20], cap, tp, tw;
void sort()
{
	int t, t1, t2;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n-i-1; j++)
		{
			if (r[j] < r[j+1])
			{
				t=r[j];
				r[j]=r[j+1];
				r[j+1]=t;
				
				t1=p[j];
				p[j]=p[j+1];
				p[j+1]=t1;
				
				t2=w[j];
				w[j]=w[j+1];
				w[j+1]=t2;
			}
		}
	}
}
void knapsack(float m, int n)
{
	for (i=0; i<n; i++)
	{
		x[i] = 0.0;
	}
	u = m;
	for (i=0; i<n; i++)
	{
		if (w[i] > u)
			break;
		x[i] = 1.0;
		u = u - w[i];
	}
	if (i <= n)
		x[i] = u / w[i];
	for (i=0; i<n; i++)
	{
		tp = tp + (p[i]*x[i]);
		tw = tw + (w[i]*x[i]);
	}
	printf("\nSolution Vector:\n");
	printf("|");
	for(i=0; i<n; i++)
		printf(" %f |", x[i]);
	printf("\n\nThe Final Profit is %f", tp);
	printf("\nThe Final Weight is %f", tw);
}
int main()
{
	printf("Enter The Capacity: ");
	scanf("%f", &cap);
	printf("Enter The Number of Elements: ");
	scanf("%d", &n);
	printf("Enter Values of Profits and Weights:\n");
	for (i=0; i<n; i++)
	{
		scanf("%f%f", &p[i], &w[i]);
	}
	for (i=0; i<n; i++)
	{
		r[i] = p[i] / w[i];
	}
	sort();
	knapsack(cap, n);
}

/*
25 18
24 15
15 10
*/
// Time complexity O(nlogn) + O(1) = O(nlogn)

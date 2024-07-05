#include<stdio.h>
#define inf 9999
int c[100][100], d[100][100];
void floyd(int n)
{
	int i, j, k;
	for(k=1; k<=n; k++)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(d[i][j] > (d[i][k] + d[k][j]))
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
}
int main()
{
	int n, i, j;
	printf("Enter The Number of Vertices: ");
	scanf("%d", &n);
	printf("Enter The Cost Matrix:\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			scanf("%d", &c[i][j]);
			if(i != j && c[i][j] == 0)
				c[i][j] = inf;
			d[i][j] = c[i][j];
		}
	}
	floyd(n);
	printf("The Shortest Paths Cost Matrix is\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("%d\t", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
0 8 0 1
0 0 1 0
4 0 0 0
0 2 9 0
*/

//Time complexity O(n^3)

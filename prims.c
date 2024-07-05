#include<stdio.h>
#define inf 9999
int g[100][100], sts[100];
int prims(int n)
{
	int i, j, k, u, v, min, min_cost=0;
	for(i=1; i<=n; i++)
		sts[i] = 0;
	sts[1] = 1;
	printf("\nEdge\t Cost\n");
	for(k=1; k<n; k++)
	{
		min = inf;
		for(i=0; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if((g[i][j] != inf) && sts[i] == 1 && sts[j] == 0)
				{
					if(g[i][j] < min)
					{
						min = g[i][j];
						u = i;
						v = j;
					}
				}
			}
		}
		sts[u] = sts[v] = 1;
		min_cost += min;
		printf("%d -> %d\t  %d\n", u, v, min);
	}
	return min_cost;
}
int main()
{
	int n, i, j, cost;
	printf("Enter The Number of Vertices: ");
	scanf("%d", &n);
	printf("Enter The Adjacency Matrix:\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			scanf("%d", &g[i][j]);
			if(g[i][j] == 0)
				g[i][j] = inf;
		}
	}
	cost = prims(n);
	printf("\nThe Cost of The MST is %d", cost);
	return 0;
}

/*
0 8 1 5 0 0
8 0 5 0 3 0
1 5 0 5 6 4
5 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0
*/


//with adjacency matrix-> O(n^3)
// with priority queue O(ElogV)

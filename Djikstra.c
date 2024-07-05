#include<stdio.h>
#define inf 9999
int cost[100][100], sts[100], dist[100];
void djsk(int n, int v)
{
	int i, c, u, w, min;
	for(i=1; i<=n; i++)
	{
		sts[i] = 0;
		dist[i] = cost[v][i];
	}
	dist[v] = 0;
	for(c=2; c<=n; c++)
	{
		min = inf;
		for(w=1; w<=n; w++)
		{
			if(dist[w] < min && sts[w] == 0)
			{
				min = dist[w];
				u = w;
			}
		}
		sts[u] = 1;
		for(w=1; w<=n; w++)
		{
			if((dist[u] + cost[u][w] < dist[w]) && (sts[w] == 0))
			{
				dist[w] = dist[u] + cost[u][w];
			}
		}
	}
}
int main()
{
	int n, v, i, j;
	printf("Enter The Number of Vertices: ");
	scanf("%d", &n);
	printf("Enter The Cost Matrix:\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j] = inf;
		}
	}
	printf("Enter The Source Vertex: ");
	scanf("%d", &v);
	djsk(n, v);
	printf("The Shortest Paths are\n");
	for(i=1; i<=n; i++)
	{
		if(i != v)
		{
			printf("%d -> %d = %d\n", v, i, dist[i]);
		}
	}
	return 0;
}

/*
0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0
*/
// Time complexity of Djisktra algo is O(v^2) but with non priority queue it drops to O(v+Elogv)

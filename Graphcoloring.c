#include<stdio.h>
int g[100][100], x[100];
int NextV(int k, int n)
{
	int j;
	while(1)
	{
		x[k] = (x[k]+1) % (n+1);
		if(x[k] == 0)
			return;
		for(j=1; j<=n; j++)
			if((g[k][j] != 0) && (x[k] == x[j]))
				break;
		if(j == n+1)
			return;
	}
}
void mCol(int k, int n)
{
	int i;
	while(1)
	{
		NextV(k, n);
		if(x[k] == 0)
			return;
		if(k == n)
		{
			printf("Graph Colouring: ");
			for(i=1; i<=n; i++)
				printf("%d\t", x[i]);
			printf("\n");
		}
		else
			mCol(k+1, n);
	}
}
int main()
{
	int i, j, n;
	printf("Enter The Number of Vertex: ");
	scanf("%d", &n);
	printf("The Adjacency Matrix is:\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			scanf("%d", &g[i][j]);
		}
	}
	mCol(1, n);
	return 0;
}

/*
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
*/


// Time Complexity O(m^v)
// m-> no. of colors   v-> no. of edges

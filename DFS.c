#include<stdio.h>
int m[100][100], vis[100], n;
void DFS(int v)
{
	int w;
	vis[v] = 1;
	printf("%d\t", v);
	for(w=1; w<=n; w++)
		if(m[v][w] == 1 && vis[w] == 0)
			DFS(w);
}
void DFT()
{
    int i;
    for(i=1; i<=n; i++)
        vis[i] = 0;
    for(i=1; i<=n; i++)
        if(vis[i] == 0) 
            DFS(i);
}
int main()
{
	int i, j;
	printf("Enter The Number of Vertices: ");
	scanf("%d", &n);
	printf("Enter The Adjacency Matrix:\n");
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d", &m[i][j]);
		printf("\n");
	DFT();
	return 0;
}

/*
0 1 1 0 0 0 0 0
1 0 0 1 1 0 0 0
1 0 0 0 0 1 1 0
0 1 0 0 0 0 0 1
0 1 0 0 0 0 0 1
0 0 1 0 0 0 0 1
0 0 1 0 0 0 0 1
0 0 0 1 1 1 1 0
*/

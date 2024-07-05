#include<stdio.h>
int m[100][100], vis[100], q[100], n, front=-1, rear=-1;
int AddQ(int val)
{
    if(front == -1 && rear == -1)
        front = rear = 0;
    else 
        rear++;
    q[rear] = val;
}
int DelQ()
{
    int t = q[front];
    if(front == rear)
        front = rear = -1;
    else 
        front++;
    return t;
}
int EmpQ()
{
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}
void BFS(int v)
{
	int u, w;
	vis[v] = 1;
	u = v;
	while(1)
	{
		printf("%d\t", u);
		for(w=1; w<=n; w++)
		{
			if(m[u][w] == 1 && vis[w] == 0)
			{
				AddQ(w);
				vis[w] = 1;
			}
		}
		if(EmpQ())
			return;
		u = DelQ();
	}
}
void BFT()
{
    int i;
    for(i=1; i<=n; i++)
        vis[i] = 0;
    for(i=1; i<=n; i++)
        if(vis[i] == 0) 
            BFS(i);
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
	BFT();
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

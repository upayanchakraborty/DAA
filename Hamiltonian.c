#include <stdio.h>
int g[6][6], x[6];
int NextV(int k, int n)
{
    int j;
    while (1)
    {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0)
            return;
        if (g[x[k - 1]][x[k]] != 0)
        {
            for (j = 1; j <= k - 1; j++)
                if (x[k] == x[j])
                    break;
            if (j == k)
                if ((k < n) || (k == n && (g[x[n]][x[1]] != 0)))
                    return;
        }
    }
}
void HamG(int k, int n)
{
    int i;
    while (1)
    {
        NextV(k, n);
        if (x[k] == 0)
            return;
        if (k == n)
        {
            printf("Hamiltonian Graph: ");
            for (i = 1; i <= n; i++)
                printf("%d\t", x[i]);
            printf("\n");
        }
        else
            HamG(k + 1, n);
    }
}
int main()
{
    int i, j, n;
    printf("Enter The Number of Vertex: ");
    scanf("%d", &n);
    printf("The Adjacency Matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    for(i=1; i<=n; i++)
		x[i] = 0;
    x[1] = 1;
    HamG(2, n);
    return 0;
}

/*
0 1 0 1 0 
1 0 1 1 1 
0 1 0 0 1 
1 1 0 0 1 
0 1 1 1 0
*/

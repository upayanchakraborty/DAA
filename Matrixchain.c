#include<stdio.h>
#define inf 9999
int p[20], m[20][20], s[20][20];

void Matrix(int n)
{
	int i, j, k, l, q;
	for(i=1; i<=n; i++)
		m[i][i] = 0;
	for(l=2; l<=n; l++)
	{
		for(i=1; i<=n-l+1; i++)
		{
			j = i+l-1;
			m[i][j] = inf;
			for(k=i; k<=j-1; k++)
			{
				q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if(q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	printf("The Optimal Cost id %d", m[1][n]);
}

void Optimal(int i, int j)
{
	if(i == j)
		printf("A%d", i);
	else
	{
		printf("(");
		Optimal(i, s[i][j]);
		Optimal(s[i][j]+1, j);
		printf(")");
	}
}

int main()
{
	int i, j, n;
	printf("Enter The Number of Dimensions: ");
	scanf("%d", &n);
	printf("Enter The Dimensions: ");
	for(i=0; i<n; i++)
		scanf("%d", &p[i]);
	Matrix(n-1);
	printf("\n");
	Optimal(1, n-1);
	printf("\nThe m table is:\n");
	for(i=1; i<n; i++)
	{
		for(j=1; j<n; j++)
		{
			if(i <= j)
				printf("%d\t", m[i][j]);
			else
				printf("\t");
		}
		printf("\n");
	}
	printf("\nThe s table is:\n");
	for(i=1; i<n; i++)
	{
		for(j=1; j<n; j++)
		{
			if(i < j)
				printf("%d\t", s[i][j]);
			else
				printf("\t");
		}
		printf("\n");
	}
	return 0;
}

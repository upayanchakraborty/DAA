#include<stdio.h>
#include<windows.h>
int x[100];
int Place(int k, int i)
{
	int j;
	for(j=1; j<=k-1; j++)
	{
		if(x[j] == i || (abs(x[j] - i) == abs(j - k)))
			return 0;
	}
	return 1;
}
void NQueens(int k, int n)
{
	int i, j, p, q;
	for(i=1; i<=n; i++)
	{
		if(Place(k, i))
		{
			x[k] = i;
			if(k == n)
			{
                Sleep(200);
				printf("Q");
				Sleep(500);
				printf("u");
				Sleep(200);
				printf("e");
				Sleep(200);
				printf("e");
				Sleep(200);
				printf("n");
				Sleep(200);
				printf(" ");
				Sleep(200);
				printf("P");
				Sleep(200);
				printf("o");
				Sleep(200);
				printf("s");
				Sleep(200);
				printf("i");
				Sleep(200);
				printf("t");
				Sleep(200);
				printf("i");
				Sleep(200);
				printf("o");
				Sleep(200);
				printf("n");
				Sleep(200);
				printf(":");
				Sleep(200);
				printf(" ");
				Sleep(500);
				for(j=1; j<=n; j++)
					
					printf("Q%d\t", x[j]);
					Sleep(500);
				printf("\n");
				printf("________________________________________________________________________________________________________________________\n");
				printf("\tThe Chess Board is:\n");
				for(p=1;p<=n;p++){
					for(q=1;q<=n;q++){
						if(q==x[p]){
						
							printf("\tQ%d\t",p);
							Sleep(500);
						}
						else{
						
							printf("\t_\t");
							Sleep(500);
						}
					}
					printf("\n");
				}
				printf("________________________________________________________________________________________________________________________\n");
			}
			else
				NQueens(k+1, n);
		}
	}
}
int main()
{
	int n;
	printf("Enter The Number of Queens: ");
	scanf("%d", &n);
	NQueens(1, n);
	return 0;
}

//Time complexity O(n!)

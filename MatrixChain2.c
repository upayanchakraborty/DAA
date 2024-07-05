#include<stdio.h>
#define inf 9999
int p[20],s[20][20],m[20][20],n,i,j,k,l,q;

void MatrixChainOrder(int p[20]){
	for(i=1; i<=n; i++){
		m[i][i]=0;
	}
	for(l=2; l<=n; l++){
		for(i=1; i<=n-l+1; i++){
			j=i+l-1;
     	    m[i][j]=inf;

     	    for (k=i; k<=j-1; k++){
				q = m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);

				if (q<m[i][j]){
					m[i][j]=q;
     			    s[i][j]=k;
			    }
		    }
	    }
	}
	printf("%d",m[1][n]);
}

void OptimalParens(int s[20][20],int i,int j){
	if(i == j){
	    printf("A%d",i);
	}
	else{
		printf("(");
	    OptimalParens(s,i,s[i][j]);
	    OptimalParens(s,s[i][j]+1,j);
        printf(")");
    }
}

int main(){
	int num;
	printf("Enter the number of dimensions: ");
	scanf("%d",&num);
	n=num-1;
	printf("Enter the dimension sequence: ");
	for(i=0;i<num;i++){
	    scanf("%d",&p[i]);
	}
	
	printf("\nThe optimal cost is: ");
	MatrixChainOrder(p);
	printf("\nThe parenthesized sequence is: ");
	OptimalParens(s,1,num-1);

	printf("\nThe multiplication cost matrix is:\n");
	for(i=1; i<=num; i++){
		for(j=1; j<=num-1; j++){
		 	if(i<=j){
				printf("%d\t",m[i][j]);
			}
			else{
			    printf("\t");
			}
		}
		printf("\n\n");
	}

	printf("S table content is:\n");
	for(i=1; i<num-1; i++){
	    for(j=2; j<num; j++){
			if(i<j){
				printf("%d\t",s[i][j]);
			}
		 	else{
			    printf("\t");
			}
		}
		printf("\n\n");
	}
	return 0;
}

// Enter the number of dimensions: 4
// Enter the dimension sequence: 2 3 4 5

// The optimal cost is: 64
// The parenthesized sequence is: ((A1A2)A3)
// The multiplication cost matrix is:
// 0       24      64

//         0       60

//                 0

// S table content is:
// 1       2

//         2

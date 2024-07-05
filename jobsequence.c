#include<stdio.h>
int d[10], p[10], slot[10], id[10], dmax;
void sort(int n)
{
    int i, j, t;
	for (i=0; i<n-1; i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (p[j] < p[j+1])
            {
                t = d[j];
    			d[j] = d[j+1];
    			d[j+1] = t;
                
                t = p[j];
    			p[j] = p[j+1];
    			p[j+1] = t;
    			
    			t = id[j];
    			id[j] = id[j+1];
    			id[j+1] = t;
            }
        }
    }
}
int job_sequence(int n)
{
    int sump=0, i, k, c=0;
    dmax = d[0];
    for(i=0; i<n; i++)
    {
        if(d[i] > dmax)
            dmax = d[i];
	}
    printf("\nMax deadline= %d\n",dmax);
    for(i=1; i<=dmax; i++)
        slot[i] = -1;
    for(i=0; i<n; i++)
    {
    	if(d[i] < dmax)
        	k = d[i];
        else
        	k = dmax;
        while(k > 0)
        {
            if(slot[k] == -1)
            {
                slot[k] = i;
                c++;
                sump += p[i];
                break;
            }
        k--;
        }
        if(c==dmax)
            break;
    }
    for(i=1; i<=dmax; i++)
    {
        printf("%d", id[slot[i]]);
        if(i < dmax)
            printf(" -> ");
    }
    return sump;
}
int main()
{
    int i, n, maxp;
    printf("Enter the number of job: ");
    scanf("%d",&n);
    printf("Enter the Job, Profit, Deadline:\n");
    for(i=0; i<n; i++)
        scanf("%d %d %d", &id[i], &p[i], &d[i]);
    sort(n);
    maxp = job_sequence(n);
    printf("\nMax profit is %d", maxp);
    printf("\nSolution vector: ");
    for(i=1; i<=dmax; i++)
        if(slot[i] != -1)
            printf(" %d\t",slot[i]);
    return 0;
}

/*
1 100 2
2 10 1
3 15 2
4 27 1
*/


//O(n^2)

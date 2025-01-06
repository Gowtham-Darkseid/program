#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
int inc[50], w[50], sum, n;
void sumset(int i, int wt, int total);
int promising(int i, int wt, int total) 
{
    return ((wt + total >= sum) && (wt == sum || wt + w[i + 1] <= sum));
}

void main() 
{
    int i, j, temp, total = 0;
    printf("\nEnter how many numbers:\n");
    scanf("%d", &n);
    printf("\nEnter %d numbers to the set:\n", n);
    for(i = 0; i < n; i++) 
{
        scanf("%d", &w[i]);
        total += w[i];
    }

    printf("\nInput the sum value to create subset:\n");
    scanf("%d", &sum);
    for(i = 0; i < n - 1; i++) 
	{
        for(j = 0; j < n - i - 1; j++) 
{
            if(w[j] > w[j + 1]) {
                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }

    printf("\nThe given %d numbers in ascending order:\n", n);
    for(i = 0; i < n; i++)
    {
        printf("%d\t", w[i]);
    }

    if(total < sum)
    {
        printf("\nSubset construction is not possible\n");
    }
    else
    {
	for(i = 0; i < n; i++)
	{
            inc[i] = 0;  // Initialize inc array to 0
        }
        printf("\nThe solution using backtracking is:\n");
        sumset(-1, 0, total);
    }
}

void sumset(int i, int wt, int total)
{
    int j;

    if(promising(i, wt, total))
    {
	if(wt == sum)
	{
	    printf("\n{\t");
	    for(j = 0; j <= i; j++)
	    {
		if(inc[j])
		{
                    printf("%d\t", w[j]);
                }
            }
            printf("}\n");
	}
	else
	{
	    inc[i + 1] = TRUE;
	    sumset(i + 1, wt + w[i + 1], total - w[i + 1]);
	    inc[i + 1] = FALSE;
	    sumset(i + 1, wt, total - w[i + 1]);
        }
    }
}

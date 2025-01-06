#include<stdio.h>
#define MAX 25
int matrix[MAX][MAX], visited_cities[MAX], limit, cost = 0;
int tsp(int c) 
{
    int count, nearest_city = -1;
    int minimum = 999, temp;
    for(count = 0; count < limit; count++) 
{
        if ((matrix[c][count] != 0) && (visited_cities[count] == 0)) {
            if (matrix[c][count] < minimum) 
{
                minimum = matrix[c][count];
                nearest_city = count;
                temp = matrix[c][count];
            }
        }
    }
    if (nearest_city != -1) 
{
        cost += temp;
    }
    return nearest_city;
}

void minimum_cost(int city)
 {
    int nearest_city;
    visited_cities[city] = 1; 
    printf("%d ", city + 1);   
    nearest_city = tsp(city);  
    if (nearest_city == -1) 
{  
        nearest_city = 0;
        printf("%d ", nearest_city + 1);
        cost += matrix[city][nearest_city]; 
        return;
   }

    minimum_cost(nearest_city);  
}
int main() 
{
    int i, j;
    printf("Enter total number of cities: ");
    scanf("%d", &limit);
    printf("\nEnter the cost matrix (use 0 for no path between cities):\n");
    for(i = 0; i < limit; i++) 
{
        for(j = 0; j < limit; j++) 
{
            scanf("%d", &matrix[i][j]);
        }
        visited_cities[i] = 0; 
    }
    printf("\nEntered cost matrix:\n");
    for(i = 0; i < limit; i++)
{
        for(j = 0; j < limit; j++) 
{
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nPath: ");
    minimum_cost(0);  
    printf("\n\nMinimum cost: %d\n", cost);
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*   TSP Code with Detailed Explanations of +1 and -1 operations             */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x;
    float y;
} City;

void build_dist_matrix(City *cities, int n, float dist[n][n])
{
    float dx;
    float dy;
    
    for (int i = 0; i < n; i++)  // Why < n? Arrays are 0-indexed, so valid indices are 0 to n-1
    {
        for (int j = 0; j < n; j++)  // Same here: 0 to n-1
        {
            if (i == j)
                dist[i][j] = 0.0f;  // Distance from city to itself is 0
            else
            {
                dx = cities[i].x - cities[j].x;
                dy = cities[i].y - cities[j].y;
                dist[i][j] = sqrtf((dx * dx) + (dy * dy));  // Euclidean distance
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

float path_length(int *arr, int n, float dist[n][n])
{
    float total = 0.0f;
    int prev = 0;  // Start from city 0 (fixed starting point)
    
    // Why n-1? We're looping through the permutation array
    // If we have 5 cities total, our permutation has 4 cities (excluding city 0)
    // So we loop from 0 to 3 (which is n-1 where n=4)
    for (int i = 0; i < n - 1; i++)
    {
        total += dist[prev][arr[i]];  // Add distance from previous city to current city
        prev = arr[i];                // Update previous city for next iteration
    }
    
    // Add distance back to starting city (city 0)
    total += dist[prev][0];
    return (total);
}

void tsp(int *arr, int l, int r, int n, float dist[n][n], float *best)
{
    float d;
    
    // Base case: when l > r, we've generated a complete permutation
    if (l == r + 1)  // Why r + 1? When l becomes greater than r, we're done
    {
        d = path_length(arr, n, dist);
        if (d < *best)
            *best = d;
        return;
    }
    
    // Generate permutations by swapping
    for (int i = l; i <= r; i++)  // Why <= r? We include the rightmost position
    {
        swap(&arr[l], &arr[i]);           // Swap current element to position l
        tsp(arr, l + 1, r, n, dist, best);  // Why l + 1? Move to next position to fix
        swap(&arr[l], &arr[i]);           // Backtrack: restore original order
    }
}

int main(void)
{
    City cities[12];
    int count = 0;
    int *arr;
    float best;
    
    // Read cities from input
    while (count < 11 && fscanf(stdin, "%f, %f", &cities[count].x, &cities[count].y) == 2)
        count++;  // Why count++? Increment after successful read
    
    if (count == 0)
        return (1);
    
    float dist[count][count];
    build_dist_matrix(cities, count, dist);
    
    // CRITICAL UNDERSTANDING: Why count - 1?
    // If we have 5 cities (indices 0,1,2,3,4):
    // - City 0 is FIXED as starting point
    // - We only permute cities 1,2,3,4 (that's 4 cities = count - 1)
    // - So our permutation array has size count - 1
    arr = malloc((count - 1) * sizeof(int));
    
    // Initialize permutation array with cities 1,2,3,...,count-1
    // Why i + 1? Because arr[0] should contain city 1, arr[1] should contain city 2, etc.
    for (int i = 0; i < count - 1; i++)
        arr[i] = i + 1;
    
    best = FLT_MAX;
    
    // Why count - 2? 
    // arr has indices 0 to (count-2)
    // If count=5, arr has size 4, so indices 0,1,2,3
    // The rightmost index is 3 = count - 2
    tsp(arr, 0, count - 2, count, dist, &best);
    
    printf("%.2f\n", best);
    free(arr);
    return (0);
}

/*
EXAMPLE WALKTHROUGH with 3 cities: (0,0), (1,0), (0,1)

count = 3
arr = malloc(2 * sizeof(int))  // count - 1 = 2
arr[0] = 1, arr[1] = 2         // Cities 1 and 2 (city 0 is fixed)

Call: tsp(arr, 0, 1, 3, dist, &best)
      tsp(permutation, left=0, right=1, total_cities=3, ...)

This will generate permutations:
- [1, 2] → path: 0 → 1 → 2 → 0
- [2, 1] → path: 0 → 2 → 1 → 0

And find the shortest one.
*/
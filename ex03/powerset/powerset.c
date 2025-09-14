#include <stdio.h>
#include <stdlib.h>

int *nums;
int *subset;
int n, target;

void print_subset(int size) {
    for (int i = 0; i < size; i++) {
        if (i > 0) printf(" ");
        printf("%d", subset[i]);
    }
    printf("\n");
}

void solve(int pos, int size, int sum) {
    // Base case: checked all numbers
    if (pos == n) {
        if (sum == target)
            print_subset(size);
        return;
    }
    
    // Choice 1: Don't include current number
    solve(pos + 1, size, sum);
    
    // Choice 2: Include current number
    subset[size] = nums[pos];
    solve(pos + 1, size + 1, sum + nums[pos]);
}

int main(int ac, char **av) {
    if (ac < 2) return 0;
    
    target = atoi(av[1]);
    n = ac - 2;
    
    nums = malloc(n * sizeof(int));
    subset = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
        nums[i] = atoi(av[i + 2]);
    
    solve(0, 0, 0);
    
    free(nums);
    free(subset);
    return 0;
}
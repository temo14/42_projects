#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple swap function
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Generate all permutations using backtracking
void permute(char *str, int start, int end) {
    // Base case: if we've fixed all positions, print the permutation
    if (start == end) {
        printf("%s\n", str);
        return;
    }
    
    // Try each character at the current position
    for (int i = start; i <= end; i++) {
        swap(&str[start], &str[i]);     // Place character at start position
        permute(str, start + 1, end);   // Recurse for remaining positions
        swap(&str[start], &str[i]);     // Backtrack (undo the swap)
    }
}

int main(int argc, char *argv[]) {
    // Validate arguments
    if (argc != 2)
        return 1;
    
    char *str = argv[1];
    int len = strlen(str);
    
    // Sort string alphabetically (for lexicographic order)
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                swap(&str[j], &str[j + 1]);
            }
        }
    }
    
    // Generate all permutations
    permute(str, 0, len - 1);
    
    return 0;
}

/*
🧠 EXAM MEMORY PATTERN:

PERMUTATION = "Try each character at each position"

ALGORITHM:
1. Fix first character (try all possibilities)
2. Recursively permute the rest
3. Backtrack and try next character

TRACE EXAMPLE: "ABC"
permute("ABC", 0, 2):
  Try A at pos 0: swap(A,A) → "ABC" → permute("ABC", 1, 2)
    Try B at pos 1: swap(B,B) → "ABC" → permute("ABC", 2, 2) → print "ABC"
    Try C at pos 1: swap(B,C) → "ACB" → permute("ACB", 2, 2) → print "ACB"
  Try B at pos 0: swap(A,B) → "BAC" → permute("BAC", 1, 2)
    ... and so on

KEY INSIGHT: Backtracking happens automatically when function returns!
*/
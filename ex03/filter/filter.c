#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Step 1: Validate arguments (ALWAYS FIRST!)
    if (argc != 2 || argv[1][0] == '\0')
        return (1);
    
    char c;
    char *pattern = argv[1];
    int pattern_len = strlen(pattern);
    int matched = 0;  // How many chars of pattern we've matched so far
    
    // Step 2: Read input character by character
    while (read(0, &c, 1) == 1) {
        
        // Step 3: Does current char continue our pattern match?
        if (c == pattern[matched]) {
            matched++;  // Yes! One more char matched
            
            // Step 4: Did we complete the pattern?
            if (matched == pattern_len) {
                // Print stars instead of the pattern
                for (int i = 0; i < pattern_len; i++)
                    printf("*");
                matched = 0;  // Reset for next potential match
            }
        } 
        else {
            // Step 5: Pattern broken - print what we had + current char
            for (int i = 0; i < matched; i++)
                printf("%c", pattern[i]);  // Print partial match
            
            // Step 6: Could current char start a new match?
            if (c == pattern[0])
                matched = 1;  // Start new potential match
            else {
                printf("%c", c);  // Just print current char
                matched = 0;      // No match started
            }
        }
    }
    
    // Step 7: Handle any leftover partial match at end of input
    for (int i = 0; i < matched; i++)
        printf("%c", pattern[i]);
    
    return (0);
}
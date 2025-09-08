#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    printf("F%d: %d", atoi(argv[1]), fibonacci(atoi(argv[1])));
}

#include <stdio.h>

#define MAX_SIZE 100

void generate_fibonacci(int limit, int fibonacci[]) {
    int num1 = 0, num2 = 1, next_num;

    for (int i = 0; i < MAX_SIZE && num1 <= limit; i++) {
        fibonacci[i] = num1;
        next_num = num1 + num2;
        num1 = num2;
        num2 = next_num;
    }
}

int main() {
    int limit;
    int fibonacci[MAX_SIZE] = {0};
    FILE *file = fopen("fibonacci.txt", "w");

    printf("Enter the limit for the Fibonacci series: ");
    scanf("%d", &limit);

    generate_fibonacci(limit, fibonacci);

    for (int i = 0; fibonacci[i] <= limit; i++) {
        fprintf(file, "%d\n", fibonacci[i]);
    }

    fclose(file);

    printf("Fibonacci series up to %d has been written to fibonacci.txt\n", limit);

    return 0;
}

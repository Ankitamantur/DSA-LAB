#include <stdio.h>

// Function to calculate the factorial of a given number
long int factorial(int number) {
    long int fact = 1;
    for (int i = 1; i <= number; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    // Open a file for writing
    FILE *file = fopen("factorial.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate the factorial of the given number
    long int fact = factorial(num);

    // Write the result to the file
    fprintf(file, "Factorial of %d is: %ld\n", num, fact);
    fclose(file);

    // Open the file for reading
    file = fopen("factorial.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100];
    fgets(line, sizeof(line), file);
    printf("%s", line);

    fclose(file);

    return 0;
}

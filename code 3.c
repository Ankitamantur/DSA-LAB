#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    // Open the file in write mode
    FILE *file = fopen("output.txt", "w");

    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Check if the number is prime
    if (isPrime(num)) {
        fprintf(file, "%d is a prime number.\n", num);
    } else {
        fprintf(file, "%d is not a prime number.\n", num);
    }

    fclose(file); // Close the file

    // Open the file in read mode
    file = fopen("output.txt", "r");
    char str[100];
    fgets(str, sizeof(str), file); // Read the line from the file
    printf("%s", str); // Print the line

    fclose(file); // Close the file

    return 0;
}

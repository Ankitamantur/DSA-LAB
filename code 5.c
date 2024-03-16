#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    int number, digit, sum = 0;

    // Open the input file in read mode
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read the number from the file
    fscanf(inputFile, "%d", &number);
    fclose(inputFile);

    // Calculate the sum of digits
    while (number > 0) {
        digit = number % 10;
        sum += digit;
        number /= 10;
    }

    // Open the output file in write mode
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write the sum of digits to the file
    fprintf(outputFile, "Sum of digits: %d\n", sum);
    fclose(outputFile);

    printf("Sum of digits calculated and written to output.txt\n");

    return 0;
}

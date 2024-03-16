#include <stdio.h>

#define MAX_SIZE 100

int main() {
    FILE *inputFile, *outputFile;
    int numbers[MAX_SIZE];
    int n, i;
    int sum = 0, max, min;
    float average;

    // Open the input file in read mode
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Open the output file in write mode
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        fclose(inputFile);
        return 1;
    }

    // Read the number of elements from the input file
    fscanf(inputFile, "%d", &n);

    // Read the elements into the array
    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &numbers[i]);
    }

    // Close the input file
    fclose(inputFile);

    // Find sum, max, min, and average
    max = numbers[0];
    min = numbers[0];
    for (i = 0; i < n; i++) {
        sum += numbers[i];
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    average = (float)sum / n;

    // Write results to the output file
    fprintf(outputFile, "Sum: %d\n", sum);
    fprintf(outputFile, "Average: %.2f\n", average);
    fprintf(outputFile, "Largest Element: %d\n", max);
    fprintf(outputFile, "Smallest Element: %d\n", min);

    // Close the output file
    fclose(outputFile);

    printf("Array operations completed. Results written to output.txt\n");

    return 0;
}

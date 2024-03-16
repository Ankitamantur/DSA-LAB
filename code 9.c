#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char operation;
    float num1, num2, result;

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

    // Read and process each line from the input file
    while (fscanf(inputFile, "%f %c %f", &num1, &operation, &num2) == 3) {
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    fprintf(outputFile, "Error: Division by zero\n");
                    continue;  // Skip writing result for this operation
                }
                break;
            default:
                fprintf(outputFile, "Error: Invalid operator\n");
                continue;  // Skip writing result for this operation
        }

        // Write the result to the output file
        fprintf(outputFile, "%.2f %c %.2f = %.2f\n", num1, operation, num2, result);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Calculations completed and results written to output.txt\n");

    return 0;
}

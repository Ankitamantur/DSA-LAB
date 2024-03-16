#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char str1[100], str2[100];
    int choice;

    // Open the input file in read mode
    inputFile = fopen("input_strings.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Open the output file in write mode
    outputFile = fopen("output_strings.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        fclose(inputFile);
        return 1;
    }

    // Read the first string from the input file
    fscanf(inputFile, "%s", str1);

    // Read the operation choice (1 for concatenation, 2 for copying, 3 for comparison)
    fscanf(inputFile, "%d", &choice);

    // Based on the operation choice, perform the corresponding string operation
    switch (choice) {
        case 1:
            // Concatenation
            fscanf(inputFile, "%s", str2);
            strcat(str1, str2);
            fprintf(outputFile, "Concatenated String: %s\n", str1);
            break;
        case 2:
            // Copying
            strcpy(str2, str1);
            fprintf(outputFile, "Copied String: %s\n", str2);
            break;
        case 3:
            // Comparison
            fscanf(inputFile, "%s", str2);
            if (strcmp(str1, str2) == 0) {
                fprintf(outputFile, "Strings are equal.\n");
            } else {
                fprintf(outputFile, "Strings are not equal.\n");
            }
            break;
        default:
            fprintf(outputFile, "Invalid operation choice.\n");
            break;
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("String operation completed and results written to output_strings.txt\n");

    return 0;
}

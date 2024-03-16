#include <stdio.h>
#include <math.h>

// Function prototypes
float calculateRectangleArea(float length, float width);
float calculateTriangleArea(float base, float height);
float calculateCircleArea(float radius);

int main() {
    // Variables to store user input
    float length, width, base, height, radius;

    // Open a file for writing
    FILE *fp = fopen("areas.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read inputs from the user
    printf("Enter the length and width of the rectangle: ");
    scanf("%f %f", &length, &width);

    printf("Enter the base and height of the triangle: ");
    scanf("%f %f", &base, &height);

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Calculate areas
    float rectangleArea = calculateRectangleArea(length, width);
    float triangleArea = calculateTriangleArea(base, height);
    float circleArea = calculateCircleArea(radius);

    // Write areas to the file
    fprintf(fp, "Rectangle Area: %.2f\n", rectangleArea);
    fprintf(fp, "Triangle Area: %.2f\n", triangleArea);
    fprintf(fp, "Circle Area: %.2f\n", circleArea);

    // Close the file
    fclose(fp);

    printf("Areas calculated and written to file 'areas.txt'.\n");

    return 0;
}

// Function to calculate the area of a rectangle
float calculateRectangleArea(float length, float width) {
    return length * width;
}

// Function to calculate the area of a triangle
float calculateTriangleArea(float base, float height) {
    return 0.5 * base * height;
}

// Function to calculate the area of a circle
float calculateCircleArea(float radius) {
    return M_PI * radius * radius;
}

#include <stdio.h>

void reverse_digits(int num, int digits[]) {
    int i = 0;
    while (num != 0) {
        digits[i++] = num % 10;
        num /= 10;
    }
}

int main() {
    FILE *file = fopen("number.txt", "r");
    int num, digits[10] = {0};
    fscanf(file, "%d", &num);
    fclose(file);

    reverse_digits(num, digits);

    int reversed_num = 0;
    int ten = 1;
    for (int i = 9; i >= 0; i--) {
        reversed_num += digits[i] * ten;
        ten *= 10;
    }

    file = fopen("number.txt", "w");
    fprintf(file, "The reversed number is %d\n", reversed_num);
    fclose(file);

    printf("The reversed number has been written to number.txt\n");

    return 0;
}

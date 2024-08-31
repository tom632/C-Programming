#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows;
    int x, y, z;
    int stars, spaces;

    printf("Enter the size of the tree: ");
    scanf("%d", &rows);

    for(x = 1; x <= rows; x++) {
        stars = x * 2 - 1;
        spaces = rows - x;

        for(z = 1; z <= spaces; z++) {
            printf(" ");
        }

        for(y = 1; y <= stars; y++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
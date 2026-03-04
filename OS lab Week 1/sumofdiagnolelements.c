#include <stdio.h>

int main() {
    int a[10][10], n, i, j;
    int sum = 0;

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        sum = sum + a[i][i];
    }

    printf("Sum of left diagonal = %d", sum);

    return 0;
}

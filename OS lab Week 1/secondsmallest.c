#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int smallest, second;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    smallest = arr[0];
    second = arr[1];

    if(second < smallest) {
        int temp = smallest;
        smallest = second;
        second = temp;
    }

    for(i = 2; i < n; i++) {
        if(arr[i] < smallest) {
            second = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < second && arr[i] != smallest) {
            second = arr[i];
        }
    }

    printf("Second smallest element = %d", second);

    return 0;
}

/**
 * ***************Question 5************************************************************
**/


#include <stdio.h>

#define SIZE 10

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

float calculateAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}

int main() {
    int numbers[SIZE] = {29, 10, 14, 37, 13, 5, 36, 48, 21, 11};

    printf("Original array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    sortArray(numbers, SIZE);

    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int max = findMax(numbers, SIZE);
    printf("Maximum value: %d\n", max);

    float average = calculateAverage(numbers, SIZE);
    printf("Average value: %.2f\n", average);

    return 0;
}

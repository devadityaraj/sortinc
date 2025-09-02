#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sort.h" 

void print_array(const char* label, int arr[], size_t n) {
    printf("%-25s: [ ", label);
    for (size_t i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void test_generic_sort(const char* algorithm_name, void (*sort_func)(void*, size_t, size_t, compare_func_t), int arr[], size_t n) {
    int* temp_arr = (int*)malloc(n * sizeof(int));
    if (!temp_arr) {
        printf("Memory allocation failed for %s\n", algorithm_name);
        return;
    }
    memcpy(temp_arr, arr, n * sizeof(int));

    printf("--- Testing %s ---\n", algorithm_name);
    print_array("Original", temp_arr, n);

    sort_func(temp_arr, n, sizeof(int), compare_ints);

    print_array("Sorted", temp_arr, n);
    free(temp_arr);
    printf("\n");
}

void test_specialized_sort(const char* algorithm_name, void (*sort_func)(int*, size_t), int arr[], size_t n) {
    int* temp_arr = (int*)malloc(n * sizeof(int));
    if (!temp_arr) {
        printf("Memory allocation failed for %s\n", algorithm_name);
        return;
    }
    memcpy(temp_arr, arr, n * sizeof(int));

    printf("--- Testing %s ---\n", algorithm_name);
    print_array("Original", temp_arr, n);

    sort_func(temp_arr, n);

    print_array("Sorted", temp_arr, n);
    free(temp_arr);
    printf("\n");
}

int main() {
    int test_data[] = {64, 34, 25, 12, 22, 11, 90, 88, 7, 21};
    size_t n = sizeof(test_data) / sizeof(test_data[0]);

    test_generic_sort("Bubble Sort", (void (*)(void*, size_t, size_t, compare_func_t))bubbleSort, test_data, n);
    test_generic_sort("Insertion Sort", (void (*)(void*, size_t, size_t, compare_func_t))insertionSort, test_data, n);
    test_generic_sort("Selection Sort", (void (*)(void*, size_t, size_t, compare_func_t))selectionSort, test_data, n);
    test_generic_sort("Merge Sort", (void (*)(void*, size_t, size_t, compare_func_t))mergeSort, test_data, n);
    test_generic_sort("Quick Sort", (void (*)(void*, size_t, size_t, compare_func_t))quickSort, test_data, n);
    test_generic_sort("Heap Sort", (void (*)(void*, size_t, size_t, compare_func_t))heapSort, test_data, n);
    test_generic_sort("Shell Sort", (void (*)(void*, size_t, size_t, compare_func_t))shellSort, test_data, n);
    test_generic_sort("Cocktail Shaker Sort", (void (*)(void*, size_t, size_t, compare_func_t))cocktailShakerSort, test_data, n);
    test_generic_sort("Comb Sort", (void (*)(void*, size_t, size_t, compare_func_t))combSort, test_data, n);
    test_generic_sort("Gnome Sort", (void (*)(void*, size_t, size_t, compare_func_t))gnomeSort, test_data, n);
    test_generic_sort("Odd-Even Sort", (void (*)(void*, size_t, size_t, compare_func_t))oddEvenSort, test_data, n);
    test_generic_sort("Cycle Sort", (void (*)(void*, size_t, size_t, compare_func_t))cycleSort, test_data, n);

    int bitonic_data[] = {8, 7, 6, 5, 4, 3, 2, 1};
    test_generic_sort("Bitonic Sort", (void (*)(void*, size_t, size_t, compare_func_t))bitonicSort, bitonic_data, 8);

    int specialized_data[] = {170, 45, 75, 90, 802, 24, 2, 66};
    size_t specialized_n = sizeof(specialized_data) / sizeof(specialized_data[0]);

    test_specialized_sort("Counting Sort", countingSort, specialized_data, specialized_n);
    test_specialized_sort("Radix Sort", radixSort, specialized_data, specialized_n);
    test_specialized_sort("Bucket Sort", bucketSort, specialized_data, specialized_n);
    test_specialized_sort("Pigeonhole Sort", pigeonholeSort, specialized_data, specialized_n);

    return 0;
}
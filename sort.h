#ifndef SORT_H
#define SORT_H

#include <stddef.h> // For size_t
#include <stdbool.h> // For bool
#include <stdlib.h> // For malloc, free, and general utilities
#include <string.h> // For memcpy
#include <assert.h> // For assert()
#include <limits.h> // For INT_MAX/INT_MIN

typedef int (*compare_func_t)(const void* a, const void* b);

//Utility Functions
static void swap_bytes(void* a, void* b, size_t size) {
    if (a == NULL || b == NULL || size == 0) return;
    unsigned char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

//standard comparison
int compare_ints(const void* a, const void* b) {
    int valA = *(const int*)a;
    int valB = *(const int*)b;
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

//1. Bubble Sort
void bubbleSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    unsigned char* arr = (unsigned char*)base;
    for (size_t i = 0; i < num - 1; i++) {
        bool swapped = false;
        for (size_t j = 0; j < num - i - 1; j++) {
            if (cmp(arr + j * size, arr + (j + 1) * size) > 0) {
                swap_bytes(arr + j * size, arr + (j + 1) * size, size);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

//2. Insertion Sort
void insertionSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    unsigned char* arr = (unsigned char*)base;
    for (size_t i = 1; i < num; i++) {
        unsigned char key[size];
        memcpy(key, arr + i * size, size);
        long j = i - 1;
        while (j >= 0 && cmp(arr + j * size, key) > 0) {
            memcpy(arr + (j + 1) * size, arr + j * size, size);
            j--;
        }
        memcpy(arr + (j + 1) * size, key, size);
    }
}

//3. Selection Sort
void selectionSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    unsigned char* arr = (unsigned char*)base;
    for (size_t i = 0; i < num - 1; i++) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < num; j++) {
            if (cmp(arr + j * size, arr + min_idx * size) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap_bytes(arr + min_idx * size, arr + i * size, size);
        }
    }
}

//4. Merge Sort
static void merge(void* base, size_t l, size_t m, size_t r, size_t size, compare_func_t cmp) {
    size_t n1 = m - l + 1;
    size_t n2 = r - m;
    unsigned char* arr = (unsigned char*)base;
    void* L = malloc(n1 * size);
    void* R = malloc(n2 * size);
    if (!L || !R) {
        if (L) free(L);
        if (R) free(R);
        return;
    }
    memcpy(L, arr + l * size, n1 * size);
    memcpy(R, arr + (m + 1) * size, n2 * size);
    size_t i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (cmp((unsigned char*)L + i * size, (unsigned char*)R + j * size) <= 0) {
            memcpy(arr + k++ * size, (unsigned char*)L + i++ * size, size);
        } else {
            memcpy(arr + k++ * size, (unsigned char*)R + j++ * size, size);
        }
    }
    while (i < n1) memcpy(arr + k++ * size, (unsigned char*)L + i++ * size, size);
    while (j < n2) memcpy(arr + k++ * size, (unsigned char*)R + j++ * size, size);
    free(L); free(R);
}
static void mergeSortHelper(void* base, size_t l, size_t r, size_t size, compare_func_t cmp) {
    if (l < r) {
        size_t m = l + (r - l) / 2;
        mergeSortHelper(base, l, m, size, cmp);
        mergeSortHelper(base, m + 1, r, size, cmp);
        merge(base, l, m, r, size, cmp);
    }
}
void mergeSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    mergeSortHelper(base, 0, num - 1, size, cmp);
}

//5. Quick Sort
static size_t partition(void* base, size_t low, size_t high, size_t size, compare_func_t cmp) {
    unsigned char* arr = (unsigned char*)base;
    void* pivot = malloc(size);
    if (!pivot) return high;
    memcpy(pivot, arr + high * size, size);
    size_t i = low;
    for (size_t j = low; j < high; j++) {
        if (cmp(arr + j * size, pivot) < 0) {
            swap_bytes(arr + i * size, arr + j * size, size);
            i++;
        }
    }
    swap_bytes(arr + i * size, arr + high * size, size);
    free(pivot);
    return i;
}
static void quickSortHelper(void* base, long low, long high, size_t size, compare_func_t cmp) {
    if (low < high) {
        size_t pi = partition(base, low, high, size, cmp);
        if ((long)pi > low) {
            quickSortHelper(base, low, pi - 1, size, cmp);
        }
        if ((long)pi < high) {
            quickSortHelper(base, pi + 1, high, size, cmp);
        }
    }
}
void quickSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    quickSortHelper(base, 0, num - 1, size, cmp);
}

//6. Heap Sort
static void heapify(void* base, size_t n, size_t i, size_t size, compare_func_t cmp) {
    unsigned char* arr = (unsigned char*)base;
    size_t largest = i;
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;
    if (l < n && cmp(arr + l * size, arr + largest * size) > 0) largest = l;
    if (r < n && cmp(arr + r * size, arr + largest * size) > 0) largest = r;
    if (largest != i) {
        swap_bytes(arr + i * size, arr + largest * size, size);
        heapify(base, n, largest, size, cmp);
    }
}
void heapSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    for (long i = num / 2 - 1; i >= 0; i--) heapify(base, num, i, size, cmp);
    for (long i = num - 1; i > 0; i--) {
        swap_bytes(base, (unsigned char*)base + i * size, size);
        heapify(base, i, 0, size, cmp);
    }
}

//7. Shell Sort
void shellSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    unsigned char* arr = (unsigned char*)base;
    for (size_t gap = num / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < num; i++) {
            void* temp = malloc(size);
            if (!temp) return;
            memcpy(temp, arr + i * size, size);
            long j = i;
            while (j >= gap && cmp(arr + (j - gap) * size, temp) > 0) {
                memcpy(arr + j * size, arr + (j - gap) * size, size);
                j -= gap;
            }
            memcpy(arr + j * size, temp, size);
            free(temp);
        }
    }
}

//8. Cocktail Shaker Sort
void cocktailShakerSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    unsigned char* arr = (unsigned char*)base;
    bool swapped = true;
    size_t start = 0, end = num - 1;
    while (swapped) {
        swapped = false;
        for (size_t i = start; i < end; i++) {
            if (cmp(arr + i * size, arr + (i + 1) * size) > 0) {
                swap_bytes(arr + i * size, arr + (i + 1) * size, size);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        end--;
        for (long i = end - 1; i >= (long)start; i--) {
            if (cmp(arr + i * size, arr + (i + 1) * size) > 0) {
                swap_bytes(arr + i * size, arr + (i + 1) * size, size);
                swapped = true;
            }
        }
        start++;
    }
}

//9. Comb Sort
void combSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    unsigned char* arr = (unsigned char*)base;
    size_t gap = num;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;
        swapped = false;
        for (size_t i = 0; i < num - gap; i++) {
            if (cmp(arr + i * size, arr + (i + gap) * size) > 0) {
                swap_bytes(arr + i * size, arr + (i + gap) * size, size);
                swapped = true;
            }
        }
    }
}

//10. Gnome Sort
void gnomeSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    unsigned char* arr = (unsigned char*)base;
    size_t index = 0;
    while (index < num) {
        if (index == 0) index++;
        if (cmp(arr + index * size, arr + (index - 1) * size) >= 0) {
            index++;
        } else {
            swap_bytes(arr + index * size, arr + (index - 1) * size, size);
            index--;
        }
    }
}

//11. Odd-Even Sort (Brick Sort)
void oddEvenSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    unsigned char* arr = (unsigned char*)base;
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (size_t i = 1; i < num - 1; i += 2) {
            if (cmp(arr + i * size, arr + (i + 1) * size) > 0) {
                swap_bytes(arr + i * size, arr + (i + 1) * size, size);
                isSorted = false;
            }
        }
        for (size_t i = 0; i < num - 1; i += 2) {
            if (cmp(arr + i * size, arr + (i + 1) * size) > 0) {
                swap_bytes(arr + i * size, arr + (i + 1) * size, size);
                isSorted = false;
            }
        }
    }
}

//12. Bitonic Sort
static void bitonicMerge(void* base, int low, int cnt, int dir, size_t size, compare_func_t cmp) {
    if (cnt > 1) {
        int k = cnt / 2;
        unsigned char* arr = (unsigned char*)base;
        for (int i = low; i < low + k; i++) {
            if (dir == (cmp(arr + i * size, arr + (i + k) * size) > 0)) {
                swap_bytes(arr + i * size, arr + (i + k) * size, size);
            }
        }
        bitonicMerge(base, low, k, dir, size, cmp);
        bitonicMerge(base, low + k, k, dir, size, cmp);
    }
}
static void bitonicSortHelper(void* base, int low, int cnt, int dir, size_t size, compare_func_t cmp) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonicSortHelper(base, low, k, 1, size, cmp);
        bitonicSortHelper(base, low + k, k, 0, size, cmp);
        bitonicMerge(base, low, cnt, dir, size, cmp);
    }
}
void bitonicSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    assert((num > 0) && "Array size must be a power of 2");
    bitonicSortHelper(base, 0, num, 1, size, cmp);
}

//13. Cycle Sort
void cycleSort(void* base, size_t num, size_t size, compare_func_t cmp) {
    assert(base != NULL && "Array cannot be NULL");
    assert(cmp != NULL && "Comparison function cannot be NULL");
    if (num <= 1) return;
    unsigned char* arr = (unsigned char*)base;
    for (size_t cycle_start = 0; cycle_start < num - 1; ++cycle_start) {
        unsigned char* item = malloc(size);
        if (!item) return;
        memcpy(item, arr + cycle_start * size, size);
        size_t pos = cycle_start;
        for (size_t i = cycle_start + 1; i < num; ++i) {
            if (cmp(arr + i * size, item) < 0) {
                pos++;
            }
        }
        if (pos == cycle_start) {
            free(item);
            continue;
        }
        while (cmp(arr + pos * size, item) == 0) {
            pos++;
        }
        if (pos != cycle_start) {
            swap_bytes(item, arr + pos * size, size);
        }
        while (pos != cycle_start) {
            pos = cycle_start;
            for (size_t i = cycle_start + 1; i < num; ++i) {
                if (cmp(arr + i * size, item) < 0) {
                    pos++;
                }
            }
            while (cmp(arr + pos * size, item) == 0) {
                pos++;
            }
            if (cmp(item, arr + pos * size) != 0) {
                swap_bytes(item, arr + pos * size, size);
            }
        }
        free(item);
    }
}

//The following algorithms are specialized for integer types

//14. Pigeonhole Sort
void pigeonholeSort(int arr[], size_t n) {
    assert(arr != NULL && "Array cannot be NULL");
    if (n <= 1) return;
    int min_val = arr[0], max_val = arr[0];
    for (size_t i = 1; i < n; i++) {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }
    int range = max_val - min_val + 1;
    int* holes = (int*)calloc(range, sizeof(int));
    if (!holes) return;
    for (size_t i = 0; i < n; i++) holes[arr[i] - min_val]++;
    size_t index = 0;
    for (int j = 0; j < range; j++) {
        while (holes[j]-- > 0) {
            arr[index++] = j + min_val;
        }
    }
    free(holes);
}

//15. Counting Sort
void countingSort(int arr[], size_t n) {
    assert(arr != NULL && "Array cannot be NULL");
    if (n <= 1) return;
    int max_val = arr[0];
    for (size_t i = 1; i < n; i++) if (arr[i] > max_val) max_val = arr[i];
    int* count = (int*)calloc(max_val + 1, sizeof(int));
    if (!count) return;
    int* output = (int*)malloc(n * sizeof(int));
    if (!output) { free(count); return; }
    for (size_t i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 1; i <= max_val; i++) count[i] += count[i - 1];
    for (long i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    memcpy(arr, output, n * sizeof(int));
    free(count); free(output);
}

//16. Radix Sort
static int getMax(int arr[], size_t n) {
    int max = arr[0];
    for (size_t i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}
static void countSortRadix(int arr[], size_t n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    if (!output) return;
    int count[10] = {0};
    for (size_t i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (long i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    memcpy(arr, output, n * sizeof(int));
    free(output);
}
void radixSort(int arr[], size_t n) {
    assert(arr != NULL && "Array cannot be NULL");
    if (n <= 1) return;
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSortRadix(arr, n, exp);
    }
}

//17. Bucket Sort
void bucketSort(int arr[], size_t n) {
    assert(arr != NULL && "Array cannot be NULL");
    if (n <= 1) return;
    const int numBuckets = 10;
    int max_val = getMax(arr, n);
    if (max_val < 0) return; // Cannot sort negative numbers
    int bucketSize = (max_val / numBuckets) + 1;
    int** buckets = (int**)calloc(numBuckets, sizeof(int*));
    if (!buckets) return;
    int* bucketCounts = (int*)calloc(numBuckets, sizeof(int));
    if (!bucketCounts) { free(buckets); return; }

    for (size_t i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        if (bucketCounts[bucketIndex] == 0) {
            buckets[bucketIndex] = (int*)malloc(n * sizeof(int));
            if (!buckets[bucketIndex]) {
                for (int j = 0; j < numBuckets; j++) if(buckets[j]) free(buckets[j]);
                free(buckets); free(bucketCounts);
                return;
            }
        }
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }
    
    size_t k = 0;
    for (int i = 0; i < numBuckets; i++) {
        if (bucketCounts[i] > 0) {
            insertionSort(buckets[i], bucketCounts[i], sizeof(int), compare_ints);
            for (int j = 0; j < bucketCounts[i]; j++) {
                arr[k++] = buckets[i][j];
            }
            free(buckets[i]);
        }
    }
    free(buckets); free(bucketCounts);
}

#endif // SORT_H
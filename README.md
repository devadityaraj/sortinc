# Sortinc Library README

# **Sortinc** ![C++](https://img.shields.io/badge/language-C-blue) ![Header-Only](https://img.shields.io/badge/header-only-brightgreen)

**Sortinc** is a **header-only C/C++ library** that provides a collection of popular sorting algorithms. It is easy to integrate into any project—simply include the header file, and you’re ready to sort arrays with a variety of algorithms. No compilation, no extra dependencies.

---

## Table of Contents

* [Features](#features)
* [Installation](#installation)
* [Sorting Algorithms](#sorting-algorithms)
* [Usage](#usage)
* [Examples](#examples)
* [Compilation](#compilation)
* [Contributing](#contributing)
* [License](#license)

---

## Features

* Header-only, lightweight, and easy to use
* Provides multiple sorting algorithms:

  * Bubble Sort
  * Selection Sort
  * Insertion Sort
  * Quick Sort
  * Merge Sort
  * Heap Sort
* Works with integer arrays, extendable to other types
* Simple integration via `install.sh` or manual copy

---

## Installation

### 1. Clone the repository

```bash
git clone https://github.com/devadityaraj/sortinc.git
cd sortinc
```

### 2. Install using the provided script

```bash
chmod +x install.sh
./install.sh
```

This will copy `sort.h` to `/usr/local/include/`, making it globally available.

### 3. Manual installation

```bash
sudo cp sort.h /usr/local/include/
```

---

## Sorting Algorithms

The library currently provides the following functions (all work on integer arrays):

| Function Name                             | Description                               |
| ----------------------------------------- | ----------------------------------------- |
| `bubbleSort(int arr[], size_t n)`         | Simple bubble sort algorithm              |
| `selectionSort(int arr[], size_t n)`      | Selects the minimum element iteratively   |
| `insertionSort(int arr[], size_t n)`      | Builds sorted array one element at a time |
| `quickSort(int arr[], int low, int high)` | Fast divide-and-conquer quick sort        |
| `mergeSort(int arr[], int l, int r)`      | Merge sort using divide-and-conquer       |
| `heapSort(int arr[], size_t n)`           | Heap sort using max heap                  |

> **Note:** For `quickSort` and `mergeSort`, pass the **start and end indices** as parameters. For other sorts, just pass the array and its size.

---

## Usage

Include the header in your project:

```c
#include <sort.h>
```

### Bubble Sort Example

```c
#include <stdio.h>
#include <sort.h>

int main() {
    int arr[] = {5, 2, 9, 1, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for(size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

### Quick Sort Example

```c
#include <stdio.h>
#include <sort.h>

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

### Merge Sort Example

```c
#include <stdio.h>
#include <sort.h>

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

### Heap Sort Example

```c
#include <stdio.h>
#include <sort.h>

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: ");
    for(size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

---

## Compilation

Compile any C/C++ program with your library like this:

```bash
gcc main.c -o main        # For C
g++ main.cpp -o main      # For C++
```

Since the library is header-only, no linking is required.

---

## Contributing

Contributions are welcome! You can:

* Add more sorting algorithms
* Optimize existing functions
* Add support for other data types (float, double, etc.)
* Improve documentation

Steps:

```bash
git fork https://github.com/devadityaraj/sortinc
git clone <your-fork>
```

---

## License

[MIT License](LICENSE) – Feel free to use, modify, and distribute.

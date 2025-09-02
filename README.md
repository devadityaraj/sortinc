# Sortinc Library

# **Sortinc** ![C++](https://img.shields.io/badge/language-C++-blue) ![Header-Only](https://img.shields.io/badge/header-only-brightgreen)

**Sortinc** is a **header-only C/C++ library** that provides a comprehensive collection of 17 popular sorting algorithms. It is designed for easy integration into any project—simply include the header file, and you’re ready to sort arrays with a variety of algorithms. No compilation or external dependencies are required.

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
* Provides 17 sorting algorithms including:

  * Bubble Sort, Insertion Sort, Selection Sort
  * Quick Sort, Merge Sort, Heap Sort
  * Shell Sort, Cocktail Shaker Sort, Comb Sort
  * Gnome Sort, Odd-Even Sort, Bitonic Sort
  * Cycle Sort, Pigeonhole Sort, Counting Sort
  * Radix Sort, Bucket Sort
* Works with generic types and integer-specific arrays
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

Sortinc provides the following functions:

| Function Name        | Description                      |
| -------------------- | -------------------------------- |
| `bubbleSort`         | Bubble Sort                      |
| `insertionSort`      | Insertion Sort                   |
| `selectionSort`      | Selection Sort                   |
| `quickSort`          | Quick Sort                       |
| `mergeSort`          | Merge Sort                       |
| `heapSort`           | Heap Sort                        |
| `shellSort`          | Shell Sort                       |
| `cocktailShakerSort` | Cocktail Shaker Sort             |
| `combSort`           | Comb Sort                        |
| `gnomeSort`          | Gnome Sort                       |
| `oddEvenSort`        | Odd-Even Sort (Brick Sort)       |
| `bitonicSort`        | Bitonic Sort (Power of 2 arrays) |
| `cycleSort`          | Cycle Sort                       |
| `pigeonholeSort`     | Pigeonhole Sort (integer arrays) |
| `countingSort`       | Counting Sort (integer arrays)   |
| `radixSort`          | Radix Sort (integer arrays)      |
| `bucketSort`         | Bucket Sort (integer arrays)     |

> **Note:** Generic sorts require `compare_func_t` comparison function; integer-specific sorts work directly with `int` arrays.

---

## Usage

Include the header in your project:

```c
#include <sort.h>
```

### Generic Sort Example 1: Bubble Sort

```c
#include <stdio.h>
#include <sort.h>

int main() {
    int arr[] = {5, 2, 9, 1, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n, sizeof(int), compare_ints);

    printf("Sorted array: ");
    for(size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
```

### Generic Sort Example 2: Quick Sort

```c
#include <stdio.h>
#include <sort.h>

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, n, sizeof(int), compare_ints);

    for(size_t i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
```

### Integer-Specific Sort Example 1: Counting Sort

```c
#include <stdio.h>
#include <sort.h>

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    countingSort(arr, n);

    for(size_t i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
```

### Integer-Specific Sort Example 2: Radix Sort

```c
#include <stdio.h>
#include <sort.h>

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    radixSort(arr, n);

    for(size_t i = 0; i < n; i++) printf("%d ", arr[i]);
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
* Add support for other data types
* Improve documentation

Steps:

```bash
git fork https://github.com/devadityaraj/sortinc
git clone <your-fork>
```

---

## License

[MIT License](LICENSE) – Free to use, modify, and distribute.

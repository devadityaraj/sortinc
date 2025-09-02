<div align="center">
<img src="https://www.google.com/search?q=https://placehold.co/150x150/F87171/FFFFFF%3Ftext%3Dsort.h" alt="sort.h Logo" style="border-radius: 50%;">
<h1>sort.h: A Header-Only C Sorting Library</h1>
<p>A fast, robust, and easy-to-use C library with a wide range of sorting algorithms.</p>
</div>
🚀 Key Features

    Header-Only: Just a single sort.h file. No separate compilation or linking is needed.

    Generic: Most algorithms can sort any data type (e.g., int, float, structs) using a custom comparison function.

    Robustness: Includes internal assertions and error handling to ensure reliability.

    Comprehensive: Provides 17 different sorting algorithms, from simple to advanced.

    Cross-Platform: Works seamlessly on Windows, Linux, and macOS.

📦 Installation

To make sort.h available system-wide, simply download the repository and run the provided installation script. The process is straightforward for all major operating systems.
1. Clone the Repository

Use git clone to download the project to your local machine:

git clone [https://github.com/devadityaraj/sortinc.git](https://github.com/devadityaraj/sortinc.git)
cd sortinc

2. Run the Installation Script

The install.sh script will automatically copy the sort.h header file to a standard system directory, allowing your compiler to find it without extra effort. You can also run it on Windows using a Git Bash or WSL terminal.

macOS & Linux

chmod +x install.sh
sudo ./install.sh

After this one-time step, you can include sort.h in any of your C projects.
👩‍💻 Usage
A Simple Demo

Include sort.h in your source code and call any of the functions. No special compiler flags are needed.

#include <stdio.h>
#include <sort.h>

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Use a generic sorting algorithm. Note the `compare_ints` function is also included in sort.h.
    bubbleSort(data, n, sizeof(int), compare_ints);

    printf("Sorted array:   ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}

Generic vs. Specialized Algorithms

Most algorithms (e.g., bubbleSort, quickSort) are generic. They require a comparison function to know how to order the elements.

Specialized algorithms (e.g., radixSort, countingSort) are optimized for integers and do not require a comparison function.

Here's how to use a specialized algorithm:

#include <stdio.h>
#include <sort.h>

int main() {
    int data[] = {170, 45, 75, 90, 802, 24, 2, 66};
    size_t n = sizeof(data) / sizeof(data[0]);

    radixSort(data, n);

    // ... your print loop here
    return 0;
}

✨ Available Algorithms

Here is a list of all the sorting algorithms included in sort.h.

Algorithm Name
	

Type
	

Best Case
	

Average Case
	

Worst Case

bubbleSort
	

Generic
	

O(n)
	

O(n2)
	

O(n2)

insertionSort
	

Generic
	

O(n)
	

O(n2)
	

O(n2)

selectionSort
	

Generic
	

O(n2)
	

O(n2)
	

O(n2)

mergeSort
	

Generic
	

O(nlogn)
	

O(nlogn)
	

O(nlogn)

quickSort
	

Generic
	

O(nlogn)
	

O(nlogn)
	

O(n2)

heapSort
	

Generic
	

O(nlogn)
	

O(nlogn)
	

O(nlogn)

shellSort
	

Generic
	

O(nlogn)
	

Varies
	

O(n2)

cocktailShakerSort
	

Generic
	

O(n)
	

O(n2)
	

O(n2)

combSort
	

Generic
	

O(nlogn)
	

O(nlogn)
	

O(n2)

gnomeSort
	

Generic
	

O(n)
	

O(n2)
	

O(n2)

oddEvenSort
	

Generic
	

O(n)
	

O(n2)
	

O(n2)

bitonicSort
	

Generic
	

O(log2n)
	

O(log2n)
	

O(log2n)

cycleSort
	

Generic
	

O(n2)
	

O(n2)
	

O(n2)

pigeonholeSort
	

Specialized
	

O(n+range)
	

O(n+range)
	

O(n+range)

countingSort
	

Specialized
	

O(n+k)
	

O(n+k)
	

O(n+k)

radixSort
	

Specialized
	

O(nk)
	

O(nk)
	

O(nk)

bucketSort
	

Specialized
	

O(n)
	

O(n)
	

O(n2)
📜 License

This project is licensed under the MIT License. See the LICENSE file for details.

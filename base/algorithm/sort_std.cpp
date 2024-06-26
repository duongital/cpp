#include <bits/stdc++.h>

using namespace std;

int main() {
  cout << "Hello, world!" << "\n";

  // sort an array
  int arr[] = {1, 3, 2, 5, 4, 7, 6};
  int n = 7;
  sort(arr, arr + n);
  for (int e : arr) {
    cout << "array: " << e << endl;
  }

  // sort a vector
  vector<int> vector2 = {3, 4, 5, 2, 1};
  sort(vector2.begin(), vector2.end());
  for (int i : vector2) {
    cout << "vector: " << i << endl;
  }
  return 0;
}

/**
Q: How std sort() is implemented?

A: The `std::sort` function in the C++ Standard Template Library (STL) is
implemented using a hybrid sorting algorithm known as Introsort. Introsort
combines three different sorting algorithms: QuickSort, HeapSort, and
InsertionSort. Here's how it works:

- **QuickSort**: By default, Introsort starts with QuickSort. QuickSort is
efficient for large datasets and performs well on average cases. However, in the
worst-case scenario (when the input is already sorted or nearly sorted),
QuickSort can degrade to O(n^2) complexity.

- **HeapSort**: If QuickSort performs poorly (indicating that the dataset might
be close to the worst case), Introsort switches to HeapSort. HeapSort has a
guaranteed O(n log n) complexity, making it a reliable fallback for
difficult-to-sort datasets.

- **InsertionSort**: When the dataset becomes small enough (typically when the
remaining portion of the dataset is less than a threshold, which is 32 by
default), Introsort switches to InsertionSort. InsertionSort is efficient for
small arrays and serves as the final polishing step to achieve the desired
sorted state.

The decision to switch between these algorithms is based on the current state of
the dataset and the performance of the previous sorting steps. Introsort
dynamically adapts to the characteristics of the data it is sorting, aiming to
balance efficiency and reliability across a wide range of scenarios.

Here's a simplified overview of how Introsort operates within the `std::sort`
function:

1. Start with QuickSort.
2. Monitor the depth of recursion (which correlates with the number of
partitions made).
3. If the recursion depth exceeds a certain threshold (logarithmic in the size
of the dataset), switch to HeapSort.
4. Continue sorting until the dataset is small enough (below a certain size
threshold), then switch to InsertionSort.

This hybrid approach allows `std::sort` to efficiently sort a wide variety of
datasets while minimizing the risk of poor performance in edge cases [2].
 */
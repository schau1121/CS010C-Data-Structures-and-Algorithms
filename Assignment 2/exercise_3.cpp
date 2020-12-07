// Assignment 2, exercise 3
// To compile, run:
//    g++ -std=c++11 exercise_3.cpp

#include <chrono>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

/*
 * Implement the 4 in-place sort functions for exercise 3.a.
 */

void insertion_sort(int array[], size_t size) {
    size_t i = 0;
    size_t j = 0;
    int temp;

    for(i = 1; i < size; i++) {
      j = i;
      while(j > 0 && array[j] < array[j - 1]) {
        temp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp;
        j--;
      }
  }
}

void quick_sort(int array[], int i, int k) {
    int l = i;
    int h = k;
    int temp;
    int pivot = array[(l + h) / 2];

    while(l <= h) {
      while (array[l] < pivot) {
        l++;
      }
      while (array[h] > pivot) {
        h--;
      }
      if (l <= h) {
        temp = array[l];
        array[l] = array[h];
        array[h] = temp;
        l++;
        h--;
      }
    };

    if (i < h) {
      quick_sort(array, i, h);
    }
    if (l < k) {
      quick_sort(array, l, k);
    }
}

void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // main function to do heap sort
  void heap_sort(int arr[], size_t n) {
    // Build max heap
    for (int i = (n - 1) / 2; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }

void merge(int array[], int i, int j, int k) {
  int mergedSize = k - i + 1;
  int mergePos = 0;
  int leftPos = 0;
  int rightPos = 0;
  int* mergedNums = new int[mergedSize];

  leftPos = i;
  rightPos = j + 1;

  while(leftPos <= j && rightPos <= k) {
    if(array[leftPos] <= array[rightPos]) {
      mergedNums[mergePos] = array[leftPos];
      leftPos++;
    }
    else {
      mergedNums[mergePos] = array[rightPos];
      rightPos++;
    }
    mergePos++;
  }

  while(leftPos <= j) {
    mergedNums[mergePos] = array[leftPos];
    leftPos++;
    mergePos++;
  }
  while(rightPos <= k) {
    mergedNums[mergePos] = array[rightPos];
    rightPos++;
    mergePos++;
  }

  for(mergePos = 0; mergePos < mergedSize; mergePos++) {
    array[i + mergePos] = mergedNums[mergePos];
  }
}

void merge_sort(int array[], int i, int k) {
  int j = 0;
  if(i < k) {
    j = (i + k) / 2;
    merge_sort(array, i, j);
    merge_sort(array, j + 1, k);

    merge(array, i, j, k);
  }
}


/*
 * Generate random integers for exercise 3.b
 */
int *random_ints(size_t size) {
  int *numbers = new int[size];
  srand(time(0));
  for(size_t i = 0; i < size; i++) {
    numbers[i] = rand() % 100001;
  }
  return numbers;
}

long long avg_time_insertion(size_t size) { //takes avg time over 30 iterations of insertion sort on varying sizes
  int i;
  long long avg;
  long long sum = 0;
  for(i = 0; i < 30; i++) {
    int* nums = random_ints(size);
    auto start_time = chrono::high_resolution_clock::now();
    insertion_sort(nums, size);
    auto end_time = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    sum = sum + elapsed.count();
  }
  avg = sum / 30.00;
  return avg;
}

long long avg_time_quick(size_t size) { //takes avg time over 30 iterations of insertion sort on varying sizes
  int i;
  long long avg;
  long long sum = 0;
  for(i = 0; i < 30; i++) {
    int* nums = random_ints(size);
    auto start_time = chrono::high_resolution_clock::now();
    quick_sort(nums, 0, size - 1);
    auto end_time = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    sum = sum + elapsed.count();
  }
  avg = sum / 30.00;
  return avg;
}

long long avg_time_heap(size_t size) { //takes avg time over 30 iterations of insertion sort on varying sizes
  int i;
  long long avg;
  long long sum = 0;
  for(i = 0; i < 30; i++) {
    int* nums = random_ints(size);
    auto start_time = chrono::high_resolution_clock::now();
    heap_sort(nums, size);
    auto end_time = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    sum = sum + elapsed.count();
  }
  avg = sum / 30.00;
  return avg;
}

long long avg_time_merge(size_t size) { //takes avg time over 30 iterations of insertion sort on varying sizes
  int i;
  long long avg;
  long long sum = 0;
  for(i = 0; i < 30; i++) {
    int* nums = random_ints(size);
    auto start_time = chrono::high_resolution_clock::now();
    merge_sort(nums, 0, size - 1);
    auto end_time = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    sum = sum + elapsed.count();
  }
  avg = sum / 30.00;
  return avg;
}

void print_nums(int array[], size_t size) {
    cout << "Printing numbers..." << endl;
    for(size_t i = 0; i < size; i++) {
      cout << array[i] << " ";
    }
}


//driver code
int main() {
    int numSize;
    cout << "Enter size of array to sort" << endl;
    cin >> numSize;
    cout << "Avg time for insertion sort:" << endl;
    cout << avg_time_insertion(numSize) << " nanoseconds" << endl;
    cout << "Avg time for quick sort:" << endl;
    cout << avg_time_quick(numSize) << " nanoseconds" << endl;
    cout << "Avg time for heap sort:" << endl;
    cout << avg_time_heap(numSize) << " nanoseconds" << endl;
    cout << "Avg time for merge sort:" << endl;
    cout << avg_time_merge(numSize) << " nanoseconds" << endl;
}


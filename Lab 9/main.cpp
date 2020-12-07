#include <cassert>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <random>

using namespace std;
using namespace std::chrono;

const size_t NUMBERS_SIZE = 50000;

void Quicksort_midpoint(int numbers[], size_t i, size_t k);
void Quicksort_medianOfThree(int numbers[], size_t i, size_t k);
void InsertionSort(int numbers[], size_t numbersSize);
int Partition(int numbers[],int i,int k);
int PartitionMedian(int numbers[], int i,int k);
void fillArrays(int[], int[], int[]);
bool isArraySorted(int[], size_t);

int main() {
  // Test sorting empty array
  int *nullArray = nullptr;
  Quicksort_midpoint(nullArray, 0, 0);
  Quicksort_medianOfThree(nullArray, 0, 0);
  InsertionSort(nullArray, 0);

  // Test sorting array of single element
  int singleArray[1];
  Quicksort_midpoint(singleArray, 0, 0);
  Quicksort_medianOfThree(singleArray, 0, 0);
  InsertionSort(singleArray, 1);

  int arr1[NUMBERS_SIZE];
  int arr2[NUMBERS_SIZE];
  int arr3[NUMBERS_SIZE];
  fillArrays(arr1, arr2, arr3);

  auto start_time = high_resolution_clock::now();
  Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
  auto end_time = high_resolution_clock::now();
  unsigned long elapsed =
      duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 1: " << elapsed << " us" << endl;
  assert(isArraySorted(arr1, NUMBERS_SIZE));

  start_time = high_resolution_clock::now();
  Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
  end_time = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 2: " << elapsed << " us" << endl;
  assert(isArraySorted(arr2, NUMBERS_SIZE));

  start_time = high_resolution_clock::now();
  InsertionSort(arr3, NUMBERS_SIZE);
  end_time = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 3: " << elapsed << " us" << endl;
  assert(isArraySorted(arr3, NUMBERS_SIZE));

  start_time = high_resolution_clock::now();
  Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
  end_time = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 1: " << elapsed << " us" << endl;
  assert(isArraySorted(arr1, NUMBERS_SIZE));

  start_time = high_resolution_clock::now();
  Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
  end_time = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 2: " << elapsed << " us" << endl;
  assert(isArraySorted(arr2, NUMBERS_SIZE));

  start_time = high_resolution_clock::now();
  InsertionSort(arr3, NUMBERS_SIZE);
  end_time = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 3: " << elapsed << " us" << endl;
  assert(isArraySorted(arr3, NUMBERS_SIZE));

  return 0;
}

void fillArrays(int arr1[], int arr2[], int arr3[]) {
  // Generate random integers using uniform distribution
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dist;
  for (size_t i = 0; i < NUMBERS_SIZE; i++) arr1[i] = dist(gen);
  // Array copy (memcpy) is generally faster
  memcpy(arr2, arr1, sizeof(int) * NUMBERS_SIZE);
  memcpy(arr3, arr1, sizeof(int) * NUMBERS_SIZE);
}      

bool isArraySorted(int arr[], size_t len) {
  if (arr == nullptr || len < 2) return true;
  for (size_t i = 0; i < len - 1; i++) {
    if (arr[i] > arr[i + 1]) return false;
  }
  return true;
}

void InsertionSort(int numbers[], size_t numbersSize) {
  if(numbersSize == 1 || numbers == nullptr) {
    return;
  }
  if(numbers == nullptr) {
    return;
  }
  size_t i = 0;
  size_t j = 0;
  int temp;
  for(i = 1; i < numbersSize; i++) {
    j = i;
    while(j > 0 && numbers[j] < numbers[j - 1]) {
      temp = numbers[j];
      numbers[j] = numbers[j - 1];
      numbers[j - 1] = temp;
      j--;
    }
  }
}

int PartitionMedian(int numbers[], int i,int k) {
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;
   
    
    midpoint = i + (k - i) / 2;
    if (numbers[i] == numbers[k]) {
        pivot = numbers[i];
    }
    else if (numbers[i] == numbers[midpoint]) {
        pivot = numbers[i];
    }
    else if (numbers[midpoint] == numbers[k]) {
        pivot = numbers[midpoint];
    }
    else {
        if((numbers[i]<numbers[midpoint] && numbers[midpoint]<numbers[k]) || (numbers[k] < numbers[midpoint] && numbers[midpoint] < numbers[i])) {
            pivot = numbers[midpoint];
        }
            else if ((numbers[midpoint] < numbers[i] && numbers[i]<k) || (numbers[k]<numbers[i] && numbers[i] <numbers[midpoint])) {
            pivot = numbers[i];
        }
        else {
            pivot = numbers[k];
        }
    }
        
    
    l = i;
    h = k;
   
    while (!done) {
        while (numbers[l] < pivot) {
            ++l;
        }
    
        while (pivot < numbers[h]) {
            --h;
      }
      
        if (l >= h) {
            done = true;
        }
        else {
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
         
            ++l;
            --h;
        }
    }
   
    return h;
}

void Quicksort_medianOfThree(int numbers[], size_t i, size_t k) {
    if (i >= k || numbers == nullptr || k == i - 1) {
        return;
    }
    int pivot = PartitionMedian(numbers,i,k);
    
    Quicksort_midpoint(numbers,i,pivot);
    Quicksort_midpoint(numbers,pivot+1,k);
} 

int Partition(int numbers[],int i,int k) {
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;
   
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];
   
    l = i;
    h = k;
   
    while (!done) {
        while (numbers[l] < pivot) {
            ++l;
        }
      
        while (pivot < numbers[h]) {
            --h;
        }

        if (l >= h) {
            done = true;
        }
        else {
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
         
            ++l;
            --h;
        }
    }
   
    return h;
}
void Quicksort_midpoint(int numbers[], size_t i, size_t k) {
    if (i >= k || numbers == nullptr || k == i - 1) {
        return;
    }
    int pivot = Partition(numbers,i,k);
    
    Quicksort_midpoint(numbers,i,pivot);
    Quicksort_midpoint(numbers,pivot+1,k);
}
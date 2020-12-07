#ifndef __HEAP_H
#define __HEAP_H

#include <iostream>
#include "PrintJob.h"

const static int MAX_HEAP_SIZE = 10;

class Heap {
 public:
  /* Initializes an empty heap. */
  Heap();

  /* Inserts a PrintJob to the heap without violating max-heap properties. */
  void enqueue(PrintJob* job);

  /* Removes the node with highest priority from the heap. Follow the algorithm
   * on priority-queue slides. */
  void dequeue();

  /* Returns the node with highest priority. */
  PrintJob* highest() const;

  /* Prints the PrintJob with highest priority in the following format:
   * Priority: priority, Job Number: jobNum, Number of Pages: numPages (Add a
   * new line at the end.) */
  void print();

  void swap(int i, int j);

  int getLeft(int i);

  int getRight(int i);

 private:
  PrintJob* arr_[MAX_HEAP_SIZE];  // This is an array of PrintJob pointers
  int numItems_;                  // current number of items in heap

  /* This function is called by dequeue function to move the new root down the
   * heap to the appropriare location. */
  void trickleDown(int x);

  // You can include additional private helper functions here
};
#endif
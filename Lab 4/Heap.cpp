#include "Heap.h"

Heap::Heap() {
    numItems_ = 0;
}

void Heap::swap(int i, int j) {
    PrintJob* temp = arr_[i];
    arr_[i] = arr_[j];
    arr_[j] = temp;
}

int Heap::getLeft(int i) {
    return (2 * i + 1);
}

int Heap::getRight(int i) {
    return (2 * i + 2);
}

void Heap::enqueue(PrintJob* job) {
    if(numItems_ < MAX_HEAP_SIZE) {
        arr_[numItems_] = job;
        int i = numItems_;
        numItems_++;
        while(i != 0 && arr_[(i - 1) / 2]->getPriority() < arr_[i]->getPriority()) {
            swap((i - 1) / 2, i);
            i = (i - 1) / 2;
        }
    }
}

void Heap::dequeue() {
    if(numItems_ > 0) {
        PrintJob* job = arr_[0];
        arr_[0] = arr_[numItems_ - 1];
        numItems_--;
        delete(job);
        trickleDown(0);
    }
}

void Heap::trickleDown(int x) {
    int l = getLeft(x);
    int r = getRight(x);
    int largest = x;

    if(l < numItems_ && arr_[l]->getPriority() > arr_[largest]->getPriority()) {
        largest = l;
    }

    if(r < numItems_ && arr_[r]->getPriority() > arr_[largest]->getPriority()) {
        largest = r;
    }

    if(x != largest) {
        swap(x, largest);
        trickleDown(largest);
    }
}

PrintJob* Heap::highest() const {
    if(numItems_ > 0) {
        return arr_[0];
    }
    else {
        return nullptr;
    }
}

void Heap::print() {
    if(numItems_ > 0) {
        PrintJob* currJob = highest();
        cout << "Priority: " << currJob->getPriority() << ", Job Number: " << currJob->getJobNumber();
        cout << ", Number of Pages: " << currJob->getPages() << endl;
    }
    else {
        cout << "Empty Queue" << endl;
    }
}
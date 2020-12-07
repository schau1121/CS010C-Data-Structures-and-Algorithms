#include <iostream>

using namespace std;

void SubsetProduct(int A[], int s, int n);

int main() {
    int size;
    int key;
    cout << "Enter number of integers:";
    cin >> size;
    int a[size];
    cout << "\nEnter array values:" << endl;
    for(int i = 0; i < size; i++) {
        cin >> a[i];
    }
    cout << "Enter s:";
    cin >> key;
    SubsetProduct(a, key, size);
    return 0;
}

void SubsetProduct(int A[], int s, int n) {
    cout << "Subset with product " << s << ":" << endl;
    if((n < 3) && (A[0] * A[1]) != s) {
        cout << "No possible subset." << endl;
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if((A[i] * A[j]) == s) {
                    cout << "{" << A[i] << ", " << A[j] << "}" << endl;
                    return;
                }
            }
        } 
        cout << "No possible subset." << endl;
    } 
}
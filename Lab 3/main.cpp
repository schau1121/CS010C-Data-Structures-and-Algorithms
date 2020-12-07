#include <iostream>
#include <vector>
#include <stdexcept>
#include <ctime>

using namespace std;

vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++) {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    T currMinValue = vals.at(index);
    unsigned minIndex = index;
    for(size_t i = index; i < vals.size(); i++) {
        if(vals.at(i)  < currMinValue) {
            minIndex = i;
            currMinValue = vals.at(i);
        }
    }
    return minIndex;
}

template<typename T>
void selection_sort(vector<T> &vals) {
    size_t i, min;
    T temp;
    for(i = 0; i < vals.size(); i++) {
        min = min_index(vals, i);
        if(min != i) {
            temp = vals.at(min);
            vals.at(min) = vals.at(i);
            vals.at(i) = temp;
        }
    }
}

template<typename T>
T getElement(vector<T> vals, int index) {
    size_t currIndex = index;
    if(index < 0 || currIndex >= vals.size()) {
        throw out_of_range("out of range exception occured");
    } else {
        return vals.at(index);
    }
}


int main() {
    srand(time(0));
    /* PART A testing
    vector<int> randNums;
    int numSize;
    cout << "Enter size of vector:" << endl;
    cin >> numSize;
    for(int i = 0; i < numSize; i++){
        randNums.push_back(rand()%101);
        cout << randNums.at(i) << " ";
    }

    selection_sort(randNums);
    cout << "\nSorted vector:" << endl;
    for(int i = 0; i < numSize; i++) {
        cout << randNums.at(i) << " ";
    }  
    */
    // PART B
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0) {
        cout << "Enter a number: " << endl;
        cin >> index;
        try {
            curChar = getElement(vals, index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch(out_of_range &excpt) {
            cout << excpt.what() << endl;
        }
    }

    return 0;
}

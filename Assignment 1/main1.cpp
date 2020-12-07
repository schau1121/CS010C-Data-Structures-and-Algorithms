#include <iostream>
#include <string>
#include <vector>

using namespace std;

string RemoveSpaces(string input);
void CheckValidPoly(string input);
void CheckValidElement(string element);
int HighestDegree(vector<string> elementsVector);

int main() {
    try{
        string inputString;
        cout << "Enter a polynomial: " ;
        getline(cin, inputString);
        string cleanString = RemoveSpaces(inputString);
        CheckValidPoly(cleanString);
    }
    catch(runtime_error& excpt) {
        cout << "Invalid Polynomial" << endl;
        cout << excpt.what() << endl;   
    }
    catch(invalid_argument& excpt) {
        cout << "Invalid Polynomial" << endl;
        cout << excpt.what() << endl;
    }
    return 0;
};

string RemoveSpaces(string input) {
    string::size_type i;
    string newInput;
    for(i = 0; i < input.size(); i++) {
        if(input[i] != ' ') {
            newInput += input[i];
        }
    }
    return newInput;
};

void CheckValidPoly(string input) {
    //check for negatives or exponentials
    //output big-o if valid polynomial
    string::size_type i, j;
    string element;
    int substringSize;
    vector<string> elementsVector;
    for(i = 0; i < input.size(); i++) {
        for(j = i + 1; j < input.size(); j++) {
            if(input[i] != '+' && input[j] == '+') {
                substringSize = j - i;
                element = input.substr(i, substringSize);
                elementsVector.push_back(element);
                break;
            }
            else if(input[j] == '-') {
                throw runtime_error("No Negation");
            }
        }
        if(j == input.size()) {
            substringSize = j - i;
            element = input.substr(i, substringSize);
            elementsVector.push_back(element);
        }
        i = j;
    }
    cout << "Parsed Elements:" << endl;
    for(i = 0; i < elementsVector.size(); i++) {
        string currElement = elementsVector.at(i);
        cout << currElement << endl;
        CheckValidElement(currElement);
    }
    cout << "Valid Polynomial!" << endl;

    int highestDegree = HighestDegree(elementsVector);
    if(highestDegree > 0) {
        cout << "Big-O complexity: O(n^" << highestDegree << ")" << endl;
    }
    else if(highestDegree == 0) {
        cout << "Big-O complexity: O(1)" << endl;
    }

    return;
};

void CheckValidElement(string element) {
    bool containsMult = false;
    bool containsExp = false;
    string exponent;
    string::size_type i, j, k; //j is the index of the '^' char, i and k are just iterators
    for (i = 0; i < element.size(); i++) {
        if(element[i] == '*') {
            containsMult = true;
        }
        else if(element[i] == '^') {
            containsExp = true;
            j = i;
        }
    }
    if(!containsMult) {
        for (k = 1; k < element.size(); k++) {
            if(element[k] == 'n') {
                throw invalid_argument("Need Multiplication Operator");
            }
        }
    }
    if(containsExp) {
        for(i = j + 1; i < element.size(); i++) {
            if(!isdigit(element[i])) {
                throw invalid_argument("Exponent must be integer");
            }
        }
    }
};

int HighestDegree(vector<string> elementsVector) {
    string currElement;
    string exponent;
    bool containsExp;
    int maxDegree = 0;
    string::size_type i, j;
    for(i = 0; i < elementsVector.size(); i++) {
        currElement = elementsVector.at(i);
        //iterate through current element and find index of '^'
        for(j = 0; j < currElement.size(); j++) {
            if(currElement[j] == '^') {
                containsExp = true;
                break;
            }
        }
        //create substring of everything after the '^' and compare to maxDegree 
        if(containsExp) {
            exponent = currElement.substr(j + 1, currElement.size() - j - 1);
            if(stoi(exponent) > maxDegree) {
                maxDegree = stoi(exponent);
            }
        }
    }
    return maxDegree;
};
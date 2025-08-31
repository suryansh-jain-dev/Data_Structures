// Design the Logic to Find a Missing Number in a Sorted Array. Given an array of n-1 distinct integers in the range of 1 to n, 
// find the missing number in it in a Sorted Array 
// (a) Linear time 
// (b) Using binary search.


// Linear Time (O(n))

#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) return i + 1;
    }
    return n;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = 8;

    cout << "Missing (Linear): " << findMissingLinear(arr, n) << endl;
    return 0;
}


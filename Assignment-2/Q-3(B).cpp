// Design the Logic to Find a Missing Number in a Sorted Array. Given an array of n-1 distinct integers in the range of 1 to n, 
// find the missing number in it in a Sorted Array 
// (a) Linear time 
// (b) Using binary search.

// (b) Binary Search (O(log n))

#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) low = mid + 1;
        else high = mid - 1;
    }
    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = 8;

    cout << "Missing (Binary Search): " << findMissingBinary(arr, n) << endl;
    return 0;
}


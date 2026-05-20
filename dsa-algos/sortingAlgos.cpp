// ======================================================
// Sorting Algorithms in C++
// This program demonstrates:
// 1. Selection Sort
// 2. Bubble Sort
// 3. Insertion Sort
// ======================================================

#include <iostream>
using namespace std;

int main() {

    int num, n;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements:" << endl;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nEntered Array:" << endl;

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    bool running = true;

    while(running) {

        cout << "\n===================================" << endl;

        cout << "Choose Sorting Algorithm:" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> num;

        switch(num) {

            // =====================================================
            // SELECTION SORT
            // =====================================================

            case 1:
            {
                /*
                    Selection Sort:
                    ----------------
                    1. Find the smallest element in the unsorted array.
                    2. Swap it with the current index.
                    3. Repeat for remaining elements.

                    Time Complexity:
                    Best   -> O(n²)
                    Average-> O(n²)
                    Worst  -> O(n²)

                    Space Complexity -> O(1)
                */

                int tempArr[n];

                // Copy original array
                for(int i = 0; i < n; i++) {
                    tempArr[i] = arr[i];
                }

                for(int i = 0; i < n - 1; i++) {

                    int minIdx = i;

                    // Find minimum element
                    for(int j = i + 1; j < n; j++) {

                        if(tempArr[j] < tempArr[minIdx]) {
                            minIdx = j;
                        }
                    }

                    // Swap if needed
                    if(minIdx != i) {

                        int temp = tempArr[i];
                        tempArr[i] = tempArr[minIdx];
                        tempArr[minIdx] = temp;
                    }
                }

                cout << "\nArray after Selection Sort:" << endl;

                for(int i = 0; i < n; i++) {
                    cout << tempArr[i] << " ";
                }

                cout << endl;

                break;
            }

            // =====================================================
            // BUBBLE SORT
            // =====================================================

            case 2:
            {
                /*
                    Bubble Sort:
                    -------------
                    1. Compare adjacent elements.
                    2. Swap them if they are in wrong order.
                    3. Largest element bubbles to the end after every pass.

                    Optimized Bubble Sort:
                    If no swaps occur in a pass,
                    array is already sorted.

                    Time Complexity:
                    Best   -> O(n)
                    Average-> O(n²)
                    Worst  -> O(n²)

                    Space Complexity -> O(1)
                */

                int tempArr[n];

                // Copy original array
                for(int i = 0; i < n; i++) {
                    tempArr[i] = arr[i];
                }

                for(int i = 0; i < n - 1; i++) {

                    bool isSwapped = false;

                    for(int j = 0; j < n - i - 1; j++) {

                        if(tempArr[j] > tempArr[j + 1]) {

                            int temp = tempArr[j];
                            tempArr[j] = tempArr[j + 1];
                            tempArr[j + 1] = temp;

                            isSwapped = true;
                        }
                    }

                    // If no swap happened, array already sorted
                    if(!isSwapped) {
                        break;
                    }
                }

                cout << "\nArray after Bubble Sort:" << endl;

                for(int i = 0; i < n; i++) {
                    cout << tempArr[i] << " ";
                }

                cout << endl;

                break;
            }

            // =====================================================
            // INSERTION SORT
            // =====================================================

            case 3:
            {
                /*
                    Insertion Sort:
                    ----------------
                    1. Divide array into sorted and unsorted parts.
                    2. Pick one element from unsorted part.
                    3. Insert it into correct position in sorted part.

                    Similar to arranging playing cards in hand.

                    Time Complexity:
                    Best   -> O(n)
                    Average-> O(n²)
                    Worst  -> O(n²)

                    Space Complexity -> O(1)
                */

                int tempArr[n];

                // Copy original array
                for(int i = 0; i < n; i++) {
                    tempArr[i] = arr[i];
                }

                for(int i = 1; i < n; i++) {

                    int curr = tempArr[i];
                    int j = i - 1;

                    // Shift larger elements to right
                    while(j >= 0 && tempArr[j] > curr) {

                        tempArr[j + 1] = tempArr[j];
                        j--;
                    }

                    // Insert current element
                    tempArr[j + 1] = curr;
                }

                cout << "\nArray after Insertion Sort:" << endl;

                for(int i = 0; i < n; i++) {
                    cout << tempArr[i] << " ";
                }

                cout << endl;

                break;
            }

            // =====================================================
            // EXIT PROGRAM
            // =====================================================

            case 4:
            {
                cout << "\nExiting Program..." << endl;
                running = false;
                break;
            }

            // =====================================================
            // INVALID INPUT
            // =====================================================

            default:
            {
                cout << "\nInvalid Choice! Please enter between 1-4." << endl;
            }
        }
    }

    return 0;
}
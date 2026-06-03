// ======================================================
// Insertion Sort in C++
// ======================================================

#include <iostream>
using namespace std;

/*
    Insertion Sort:
    ----------------
    1. Divide the array into two parts:
       - Sorted Part
       - Unsorted Part

    2. Assume the first element is already sorted.

    3. Pick the next element from the unsorted part.

    4. Compare it with elements in the sorted part
       and shift larger elements one position to the right.

    5. Insert the current element at its correct position.

    6. Repeat until the entire array is sorted.

    Time Complexity:
    Best    -> O(n)
    Average -> O(n²)
    Worst   -> O(n²)

    Space Complexity:
    O(1)
*/

// Function for Ascending Order Insertion Sort
void insertionSortAscending(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;

        // Shift larger elements to the right
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert current element at correct position
        arr[j + 1] = current;
    }
}

// Function for Descending Order Insertion Sort
void insertionSortDescending(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;

        // Shift smaller elements to the right
        while (j >= 0 && arr[j] < current)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert current element at correct position
        arr[j + 1] = current;
    }
}

// Function to Print Array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int choice;

    cout << "\n===================================" << endl;
    cout << "1. Sort in Ascending Order" << endl;
    cout << "2. Sort in Descending Order" << endl;
    cout << "3. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        insertionSortAscending(arr, n);

        cout << "\nArray after Ascending Insertion Sort:" << endl;
        printArray(arr, n);
        break;
    }

    case 2:
    {
        insertionSortDescending(arr, n);

        cout << "\nArray after Descending Insertion Sort:" << endl;
        printArray(arr, n);
        break;
    }

    case 3:
    {
        cout << "\nExiting Program..." << endl;
        break;
    }

    default:
    {
        cout << "\nInvalid Choice! Please enter between 1-3." << endl;
    }
    }

    return 0;
}
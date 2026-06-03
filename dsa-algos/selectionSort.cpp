// ======================================================
// Selection Sort in C++
// ======================================================

#include <iostream>
using namespace std;

/*
    Selection Sort:
    ----------------
    1. Divide the array into two parts:
       - Sorted Part
       - Unsorted Part

    2. Find the smallest element (for ascending)
       or largest element (for descending)
       from the unsorted part.

    3. Swap it with the current index.

    4. Repeat for the remaining elements.

    Time Complexity:
    Best    -> O(n²)
    Average -> O(n²)
    Worst   -> O(n²)

    Space Complexity:
    O(1)
*/

// Function for Ascending Order Selection Sort
void selectionSortAscending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // Find the smallest element
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap current element with smallest element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function for Descending Order Selection Sort
void selectionSortDescending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;

        // Find the largest element
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }

        // Swap current element with largest element
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
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
        selectionSortAscending(arr, n);

        cout << "\nArray after Ascending Selection Sort:" << endl;
        printArray(arr, n);
        break;
    }

    case 2:
    {
        selectionSortDescending(arr, n);

        cout << "\nArray after Descending Selection Sort:" << endl;
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
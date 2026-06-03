// ======================================================
// Bubble Sort in C++
// ======================================================

#include <iostream>
using namespace std;

/*
    Bubble Sort:
    -------------
    1. Compare adjacent elements.
    2. Swap them if they are in the wrong order.
    3. After each pass, the largest (or smallest)
       element moves to its correct position.
    4. Repeat until the array is sorted.

    Optimized Bubble Sort:
    If no swaps occur during a pass,
    the array is already sorted.

    Time Complexity:
    Best    -> O(n)
    Average -> O(n²)
    Worst   -> O(n²)

    Space Complexity:
    O(1)
*/

// Function for Ascending Order Bubble Sort
void bubbleSortAscending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                isSwapped = true;
            }
        }

        // If no swaps occurred, array is already sorted
        if (!isSwapped)
        {
            break;
        }
    }
}

// Function for Descending Order Bubble Sort
void bubbleSortDescending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                isSwapped = true;
            }
        }

        // If no swaps occurred, array is already sorted
        if (!isSwapped)
        {
            break;
        }
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
        bubbleSortAscending(arr, n);

        cout << "\nArray after Ascending Bubble Sort:" << endl;
        printArray(arr, n);
        break;
    }

    case 2:
    {
        bubbleSortDescending(arr, n);

        cout << "\nArray after Descending Bubble Sort:" << endl;
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
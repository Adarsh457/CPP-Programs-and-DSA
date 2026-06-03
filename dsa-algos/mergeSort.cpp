// ======================================================
// Merge Sort in C++
// ======================================================

#include <iostream>
using namespace std;

/*
    Merge Sort:
    ------------
    1. Divide the array into two halves.
    2. Recursively sort both halves.
    3. Merge the sorted halves into a single sorted array.
    4. Repeat until the entire array is sorted.

    Uses Divide and Conquer approach.

    Time Complexity:
    Best    -> O(n log n)
    Average -> O(n log n)
    Worst   -> O(n log n)

    Space Complexity:
    O(n)
*/

// Function to Merge Arrays in Ascending Order
void mergeAscending(int arr[], int start, int mid, int end)
{
    int size1 = mid - start + 1;
    int size2 = end - mid;

    int left[size1], right[size2];

    // Copy elements into temporary arrays
    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < size2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    // Merge the arrays
    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements
    while (i < size1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Merge Sort for Ascending Order
void mergeSortAscending(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSortAscending(arr, start, mid);
    mergeSortAscending(arr, mid + 1, end);

    mergeAscending(arr, start, mid, end);
}

// Function to Merge Arrays in Descending Order
void mergeDescending(int arr[], int start, int mid, int end)
{
    int size1 = mid - start + 1;
    int size2 = end - mid;

    int left[size1], right[size2];

    // Copy elements into temporary arrays
    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < size2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    // Merge the arrays
    while (i < size1 && j < size2)
    {
        if (left[i] >= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements
    while (i < size1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Merge Sort for Descending Order
void mergeSortDescending(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSortDescending(arr, start, mid);
    mergeSortDescending(arr, mid + 1, end);

    mergeDescending(arr, start, mid, end);
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
        mergeSortAscending(arr, 0, n - 1);

        cout << "\nArray after Ascending Merge Sort:" << endl;
        printArray(arr, n);
        break;
    }

    case 2:
    {
        mergeSortDescending(arr, 0, n - 1);

        cout << "\nArray after Descending Merge Sort:" << endl;
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
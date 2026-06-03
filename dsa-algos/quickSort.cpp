// ======================================================
// Quick Sort in C++
// ======================================================

#include <iostream>
using namespace std;

/*
    Quick Sort:
    ------------
    1. Select a pivot element.
    2. Place the pivot at its correct position.
    3. Elements smaller than pivot go to the left.
    4. Elements larger than pivot go to the right.
    5. Recursively sort the left and right partitions.

    Uses Divide and Conquer approach.

    Time Complexity:
    Best    -> O(n log n)
    Average -> O(n log n)
    Worst   -> O(n²)

    Space Complexity:
    O(log n)
*/

// Partition Function for Ascending Order
int partitionAscending(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    return i + 1;
}

// Quick Sort for Ascending Order
void quickSortAscending(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partitionAscending(arr, start, end);

        quickSortAscending(arr, start, pivotIndex - 1);
        quickSortAscending(arr, pivotIndex + 1, end);
    }
}

// Partition Function for Descending Order
int partitionDescending(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] > pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    return i + 1;
}

// Quick Sort for Descending Order
void quickSortDescending(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partitionDescending(arr, start, end);

        quickSortDescending(arr, start, pivotIndex - 1);
        quickSortDescending(arr, pivotIndex + 1, end);
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
        quickSortAscending(arr, 0, n - 1);

        cout << "\nArray after Ascending Quick Sort:" << endl;
        printArray(arr, n);
        break;
    }

    case 2:
    {
        quickSortDescending(arr, 0, n - 1);

        cout << "\nArray after Descending Quick Sort:" << endl;
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
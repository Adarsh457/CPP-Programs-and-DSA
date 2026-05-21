// ======================================================
// Sorting Algorithms in C++
// This program demonstrates:
// 1. Selection Sort
// 2. Bubble Sort
// 3. Insertion Sort
// 4. Merge Sort
// 5. Quick Sort
// ======================================================

#include <iostream>
using namespace std;

// ======================================================
// MERGE SORT FUNCTIONS
// ======================================================

void merge(int arr[], int start, int mid, int end)
{

    int size1 = mid - start + 1;
    int size2 = end - mid;

    int left[size1], right[size2];

    // Copy data into temp arrays
    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < size2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    // Merge arrays
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

    // Remaining elements
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

void mergeSort(int arr[], int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // Left part
    mergeSort(arr, start, mid);

    // Right part
    mergeSort(arr, mid + 1, end);

    // Merge both parts
    merge(arr, start, mid, end);
}

// ======================================================
// QUICK SORT FUNCTIONS
// ======================================================

int partition(int arr[], int start, int end)
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

void quickSort(int arr[], int start, int end)
{

    if (start < end)
    {

        int pivotIndex = partition(arr, start, end);

        // Left side
        quickSort(arr, start, pivotIndex - 1);

        // Right side
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main()
{

    int num, n;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nEntered Array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    bool running = true;

    while (running)
    {

        cout << "\n===================================" << endl;

        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> num;

        switch (num)
        {

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
            for (int i = 0; i < n; i++)
            {
                tempArr[i] = arr[i];
            }

            for (int i = 0; i < n - 1; i++)
            {

                int minIdx = i;

                // Find minimum element
                for (int j = i + 1; j < n; j++)
                {

                    if (tempArr[j] < tempArr[minIdx])
                    {
                        minIdx = j;
                    }
                }

                // Swap if needed
                if (minIdx != i)
                {

                    int temp = tempArr[i];
                    tempArr[i] = tempArr[minIdx];
                    tempArr[minIdx] = temp;
                }
            }

            cout << "\nArray after Selection Sort:" << endl;

            for (int i = 0; i < n; i++)
            {
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
            for (int i = 0; i < n; i++)
            {
                tempArr[i] = arr[i];
            }

            for (int i = 0; i < n - 1; i++)
            {

                bool isSwapped = false;

                for (int j = 0; j < n - i - 1; j++)
                {

                    if (tempArr[j] > tempArr[j + 1])
                    {

                        int temp = tempArr[j];
                        tempArr[j] = tempArr[j + 1];
                        tempArr[j + 1] = temp;

                        isSwapped = true;
                    }
                }

                // If no swap happened, array already sorted
                if (!isSwapped)
                {
                    break;
                }
            }

            cout << "\nArray after Bubble Sort:" << endl;

            for (int i = 0; i < n; i++)
            {
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
            for (int i = 0; i < n; i++)
            {
                tempArr[i] = arr[i];
            }

            for (int i = 1; i < n; i++)
            {

                int curr = tempArr[i];
                int j = i - 1;

                // Shift larger elements to right
                while (j >= 0 && tempArr[j] > curr)
                {

                    tempArr[j + 1] = tempArr[j];
                    j--;
                }

                // Insert current element
                tempArr[j + 1] = curr;
            }

            cout << "\nArray after Insertion Sort:" << endl;

            for (int i = 0; i < n; i++)
            {
                cout << tempArr[i] << " ";
            }

            cout << endl;

            break;
        }

            // =====================================================
            // MERGE SORT
            // =====================================================

        case 4:
        {
            /*
                Merge Sort:
                ------------
                1. Divide array into two halves.
                2. Recursively sort both halves.
                3. Merge sorted halves.

                Time Complexity:
                Best   -> O(n log n)
                Average-> O(n log n)
                Worst  -> O(n log n)

                Space Complexity -> O(n)
            */

            int tempArr[n];

            // Copy original array
            for (int i = 0; i < n; i++)
            {
                tempArr[i] = arr[i];
            }

            mergeSort(tempArr, 0, n - 1);

            cout << "\nArray after Merge Sort:" << endl;

            for (int i = 0; i < n; i++)
            {
                cout << tempArr[i] << " ";
            }

            cout << endl;

            break;
        }

            // =====================================================
            // QUICK SORT
            // =====================================================

        case 5:
        {
            /*
                Quick Sort:
                ------------
                1. Choose a pivot element.
                2. Place pivot at correct position.
                3. Smaller elements go left,
                   larger go right.
                4. Recursively sort both parts.

                Time Complexity:
                Best   -> O(n log n)
                Average-> O(n log n)
                Worst  -> O(n²)

                Space Complexity -> O(log n)
            */

            int tempArr[n];

            // Copy original array
            for (int i = 0; i < n; i++)
            {
                tempArr[i] = arr[i];
            }

            quickSort(tempArr, 0, n - 1);

            cout << "\nArray after Quick Sort:" << endl;

            for (int i = 0; i < n; i++)
            {
                cout << tempArr[i] << " ";
            }

            cout << endl;

            break;
        }

            // =====================================================
            // EXIT PROGRAM
            // =====================================================

        case 6:
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
            cout << "\nInvalid Choice! Please enter between 1-6." << endl;
        }
        }
    }

    return 0;
}
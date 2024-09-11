// EXPERIMENT- 12
//  12. Perform Linear Search and Binary Search on an array. Description of programs:
//  a. ReadanArray of integers.
//  b. Input elements from the user for searching.
//  c. Search the elements by passing the array to a function and then return the position of
//  the element from the function else return-1 if the element is not found.
//  INPUT
#include <iostream>
#include <algorithm>
using namespace std;
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, key, choice;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> key;
    // Linear Search
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1)
    {
        cout << "Element found at index " << linearResult << " using Linear Search.\n";
    }
    else
    {
        cout << "Element not found using Linear Search.\n";
    }
    sort(arr, arr + n);
    // Binary Search
    int binaryResult = binarySearch(arr, n, key);
    if (binaryResult != -1)
    {
        cout << "Element found at index " << binaryResult << " using Binary Search.\n";
    }
    else
    {
        cout << "Element not found using Binary Search.\n";
    }
    return 0;
}

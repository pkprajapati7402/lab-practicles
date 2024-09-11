// EXPERIMENT- 13
//  13. Implement Searching using Hashing Method.
//  INPUT
#include <iostream>
using namespace std;
class HashTable
{
private:
    int *table;
    int size;
    int currentSize;

public:
    HashTable(int size)
    {
        this->size = size;
        table = new int[size];
        currentSize = 0;
        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
        }
    }
    int hashFunction(int key)
    {
        return key % size;
    }
    void insert(int key)
    {
        if (currentSize == size)
        {
            cout << "Hash Table is full!" << endl;
            return;
        }
        int hashIndex = hashFunction(key);
        while (table[hashIndex] != -1)
        {
            hashIndex = (hashIndex + 1) % size;
        }
        table[hashIndex] = key;
        currentSize++;
    }
    int search(int key)
    {
        int hashIndex = hashFunction(key);
        int startIndex = hashIndex;
        while (table[hashIndex] != -1)
        {
            if (table[hashIndex] == key)
            {
                return hashIndex;
            }
            hashIndex = (hashIndex + 1) % size;
            if (hashIndex == startIndex)
            {
                return -1;
            }
        }
        return -1;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i] != -1)
            {
                cout << "Index " << i << ": " << table[i] << endl;
            }
            else
            {
                cout << "Index " << i << ": empty" << endl;
            }
        }
    }
    ~HashTable()
    {
        delete[] table;
    }
};
int main()
{
    int size, numElements, key;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    HashTable ht(size);
    cout << "Enter the number of elements to insert: ";
    cin >> numElements;
    for (int i = 0; i < numElements; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> key;
        ht.insert(key);
    }
    cout << "\nHash Table after insertion:\n";
    ht.display();
    cout << "\nEnter the element to search: ";
    cin >> key;
    int index = ht.search(key);
    if (index != -1)
    {
        cout << "Element found at index " << index << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}

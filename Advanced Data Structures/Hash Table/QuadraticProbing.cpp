#include<bits/stdc++.h>
#define SIZE 10

using namespace std;

int hashFunction(int key)
{
    return key % SIZE;
}

int probe(int hashTable[], int key)
{
    int index = hashFunction(key);
    int i = 0;
    int turn = 0;
    while (hashTable[(index + i) % SIZE] != 0)
    {
        turn++;
        i = ((int) pow(turn, 2)) % SIZE;
    }

    return (index + i) % SIZE;
}

void Insert(int hashTable[], int data)
{
    int index = hashFunction(data);
    int turn = 0;
    while(hashTable[index] != 0)
    {
        index = probe(hashTable, data);
    }
    hashTable[index] = data;
}

int Search(int hashTable[], int key)
{
    int index = hashFunction(key);
    int lastVal = (index == 0 ? SIZE - 1 : index - 1);

    if (hashTable[index] == key)
    {
        return index;
    }

    int turn = 0;
    do
    {
        if (index == lastVal)
        {
            return -1;
        }

        turn++;
        index = (index + (int) pow(turn, 2)) % SIZE;

    } while (hashTable[index] != key);

    return index;
}


int main()
{
    int hashTable[10];
    for(int i=0; i<10; i++)
    {
        hashTable[i] = 0;
    }

    Insert(hashTable, 26);
    Insert(hashTable, 30);
    Insert(hashTable, 23);
    Insert(hashTable, 24);
    Insert(hashTable, 43);
    Insert(hashTable, 74);
    Insert(hashTable, 19);

    for(int i=0; i<10; i++)
    {
        printf("%d ", hashTable[i]);
    }
    printf("\n");

    cout << "Index of 30: " << Search(hashTable, 30) << "\n";
    cout << "Index of 74: " << Search(hashTable, 74) << "\n";
    cout << "Index of 100: " << Search(hashTable, 100) << "\n";
    cout << "Index of 5025: " << Search(hashTable, 5025) << "\n";
    cout << "Index of 19: " << Search(hashTable, 19) << "\n";
}
#include<bits/stdc++.h>
#define SIZE 10

using namespace std;

int hashFunction1(int key)
{
    return key % SIZE;
}

int hashFunction2(int key)
{
    return 7 - (key % 7);
}

void Insert(int hashTable[], int data)
{
    int index = hashFunction1(data);
    while(hashTable[index] != 0)
    {
        index = (index == SIZE) ? 0 : (index + hashFunction2(data)) % SIZE;
    }
    hashTable[index] = data;
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
}
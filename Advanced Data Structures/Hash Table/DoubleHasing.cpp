#include<bits/stdc++.h>

using namespace std;

int hashFunction1(int key)
{
    return key%10;
}

int hashFunction2(int key)
{
    return 7 - (key % 7);
}

void Insert(int hashTable[], int n, int data)
{
    int index = hashFunction1(data);
    while(hashTable[index] != 0)
    {
        index = (index == n) ? 0 : (index + hashFunction2(data)) % n;
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

    Insert(&hashTable[hashFunction1(26)], 10, 26);
    Insert(&hashTable[hashFunction1(30)], 10, 30);
    Insert(&hashTable[hashFunction1(23)], 10, 23);
    Insert(&hashTable[hashFunction1(25)], 10, 24);
    Insert(&hashTable[hashFunction1(43)], 10, 43);
    Insert(&hashTable[hashFunction1(74)], 10, 74);
    //Insert(&hashTable[hashFunction(19)], 10, 19);

    for(int i=0; i<10; i++)
    {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}
#include<bits/stdc++.h>

using namespace std;

int hashFunction(int key)
{
    return key%10;
}

void Insert(int hashTable[], int n, int data)
{
    int index = hashFunction(data);
    int turn = 0;
    while(hashTable[index] != 0)
    {
        index = (index == n) ? 0 : (index + (int) pow(turn, 2)) % n;
        turn++;
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

    Insert(&hashTable[hashFunction(26)], 10, 26);
    Insert(&hashTable[hashFunction(30)], 10, 30);
    Insert(&hashTable[hashFunction(23)], 10, 23);
    Insert(&hashTable[hashFunction(25)], 10, 24);
    Insert(&hashTable[hashFunction(43)], 10, 43);
    Insert(&hashTable[hashFunction(74)], 10, 74);
    //Insert(&hashTable[hashFunction(19)], 10, 19);

    for(int i=0; i<10; i++)
    {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}
#include <bits/stdc++.h>
#include "Chains.h"

using namespace std;


// hash function
int hashFucntion(int key)
{
    return key%10;
}

// insert into hashtable
void Insert(struct Node *hashTable[], int data)
{
    int index = hashFucntion(data);
    SortedInsert(&hashTable[index] , data);
}


int main()
{
    // Declare hastable
    struct Node *HT[10];

    for(int i=0; i<10; i++)
    {
        HT[i] = NULL;
    }
    
    for(int i=1; i<=20; i++)
    {
        Insert(HT,i);
    }

        
    struct Node *temp = Search(HT[hashFucntion(15)], 15);
    printf("%d\n", temp->data);

}
#include<bits/stdc++.h>

using namespace std;

struct Node 
{
    int data;
    struct Node *next;
};

// Insertions

void insert(struct Node **head, int data)
{
    struct Node *node = new Node();
    node->data = data;
    node->next = *head;
    *head = node;
}

void insertAt(struct Node **head, int data, int index)
{
    struct Node *currentNode = *head;
    for(int i=1; i<index-1 && currentNode; i++)
    {
        currentNode = currentNode->next;
    }
    struct Node *node = new Node();
    node->data = data;
    node->next = currentNode->next;
    currentNode->next = node;
}

void middleInsert(struct Node **head, int data)
{
    struct Node *currentNode = *head;
    int length = 0;
    while (currentNode)
    {
        length++;
        currentNode = currentNode->next;
    }
    currentNode = *head;
    for(int i=1; i<(length/2)-1 && currentNode; i++)
    {
        currentNode = currentNode->next;
    }
    struct Node *node = new Node();
    node->data = data;
    node->next = currentNode->next;
    currentNode->next = node;
}

void append(struct Node **head, int data)
{
    struct Node *currentNode = *head;
    while (currentNode->next)
    {
        currentNode = currentNode->next;
    }
    
    struct Node *node = new Node();
    node->data = data;
    node->next = NULL;
    currentNode->next = node;
}

// Deletions

void pop(struct Node **head)
{
    struct Node *deleteNode = *head, *nextNode = deleteNode->next;
    *head = nextNode;
    delete deleteNode;
}

void deleteNode(struct Node **head, int key)
{
    struct Node *deleteNode = *head, *prev = deleteNode;
    while (deleteNode && deleteNode->data != key)
    {
        prev = deleteNode;
        deleteNode = deleteNode->next;
    }
    
    if(deleteNode)
    {
        prev->next = deleteNode->next;
        delete deleteNode;
    } else {
        cout << "Key not found\n";
        return;
    }
}

void middleDelete(struct Node **head)
{
    struct Node *currentNode = *head;
    int length = 0;
    while (currentNode)
    {
        length++;
        currentNode = currentNode->next;
    }
    currentNode = *head;
    for(int i=1; i<(length/2)-1 && currentNode; i++)
    {
        currentNode = currentNode->next;
    }
    struct Node *deleteNode = new Node();
    deleteNode = currentNode->next;
    currentNode->next = deleteNode->next;
    delete deleteNode;
}

void deleteEnd(struct Node **head)
{
    struct Node *currentNode = *head;
    while (currentNode->next->next)
    {
        currentNode = currentNode->next;
    }
    
    struct Node *deleteNode;
    deleteNode = currentNode->next;
    currentNode->next = NULL;
    delete deleteNode;
}


void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    struct Node *head = NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
    insert(&head,50);
    insert(&head,60);
    print(head);
    deleteNode(&head,20);
    print(head);
    deleteNode(&head,50);
    print(head);
    deleteNode(&head,100);
    print(head);
    append(&head,100);
    print(head);
    insertAt(&head,90,3);
    print(head);
    middleInsert(&head,55);
    print(head);
    pop(&head);
    print(head);
    middleInsert(&head,65);
    print(head);
    middleDelete(&head);
    print(head);
    deleteEnd(&head);
    print(head);
}
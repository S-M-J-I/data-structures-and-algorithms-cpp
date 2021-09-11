#include<bits/stdc++.h>

using namespace std;

struct Node 
{
    int data;
    struct Node *next, *prev;
};

// Insertions

void insertFirst(struct Node **head, int data)
{
    struct Node *node = new Node();
    node->data = data;
    node->next = *head;
    node->prev = NULL;
    *head = node;
    return;
}

void middleInsert(struct Node **head, int data)
{
    if(head==NULL)
    {
        struct Node *node = new Node();
        node->data = data;
        node->next = node->prev = NULL;
        *head = node;
        return;
    }
    
    struct Node *currentNode = *head, *temp;
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
    temp = currentNode->next;
    temp->prev = currentNode;
    struct Node *node = new Node();
    node->data = data;
    currentNode->next = node;
    node->prev = currentNode;
    node->next = temp;
    temp->prev = node;
}

void insertLast(struct Node **head, int data)
{
    struct Node *node = new Node();
    struct Node *current = *head;

    node->data = data;
    node->next = NULL;

    if(head == NULL) {
        *head = node;
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }
    
    current->next = node;
    return;
}

// Deletions

void deleteFirst(struct Node **head)
{
    if(head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    struct Node *deleteNode = *head, *nextNode = deleteNode->next;
    *head = nextNode;
    delete deleteNode;
}

void deleteMiddle(struct Node **head)
{
    if(head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    struct Node *currentNode = *head;
    int length = 0;
    while (currentNode)
    {
        length++;
        currentNode = currentNode->next;
    }
    currentNode = *head;
    for(int i=1; i<(length/2)-1; i++)
    {
        currentNode = currentNode->next;
    }
    struct Node *deleteNode = currentNode->next;
    currentNode->next = deleteNode->next;
    deleteNode->next->prev = currentNode;
    delete deleteNode;
}


void deleteLast(struct Node **head)
{
    if(head==NULL)
    {
        cout << "List Empty\n";
        return;
    }

    struct Node *currentNode = *head;
    while (currentNode->next->next)
    {
        currentNode = currentNode->next;
    }
    
    struct Node *deleteNode = currentNode->next;
    currentNode->next = NULL;
    delete deleteNode;
}


void print(struct Node *head)
{
    struct Node *temp = head;
    cout << "NULL";
    while (temp)
    {
        cout << " <- " << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    struct Node *head = NULL;
    insertFirst(&head,10);
    insertFirst(&head,20);
    insertFirst(&head,30);
    insertFirst(&head,40);
    insertFirst(&head,50);
    insertFirst(&head,60);
    insertLast(&head,90);
    insertLast(&head,180);

    print(head);

    middleInsert(&head,77);

    print(head);

    deleteFirst(&head);
    print(head);

    deleteLast(&head);
    print(head);

    deleteMiddle(&head);
    print(head);
}
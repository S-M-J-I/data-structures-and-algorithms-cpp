#ifndef Chains_h
#define Chains_h
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **head, int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head_ref = *head;
    node->data = data;
    if (*head == nullptr)
    {
        node->next = nullptr;
        *head = node;
    }
    else if (node->data < head_ref->data)
    {
        node->next = head_ref;
        *head = node;
    }
    else
    {
        struct Node *current = *head;
        while(current->next != nullptr && current->next->data < node->data)
        {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
    }

    return;
}

struct Node * Search(struct Node *head, int key)
{
    struct Node *current = head;
    while(current)
    {
        if(current->data == key)
        {
            return current;
        }

        current = current->next;
    }

    printf("No such data in HashTable\n");
    return NULL;
}


#endif /* Chains_h */
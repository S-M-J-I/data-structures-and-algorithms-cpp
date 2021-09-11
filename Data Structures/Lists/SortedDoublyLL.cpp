#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next, *prev;
};

void push(struct Node **head, int data)
{

    struct Node *node = new Node();
    struct Node *head_ref = *head;
    node->data = data;
    
    if(*head == NULL)
    {
        *head = node;
        return;
    }else if (head_ref->data > node->data) {
        node->next = head_ref;
        node->next->prev = node;
        head_ref = node;
        *head = node;
    }else {

        struct Node *current = head_ref;
        while(current->next != NULL && current->next->data < node->data){
            current = current->next;
        }

        node->next = current->next;
        if(current->next != NULL)
            node->next->prev = node;
  
        current->next = node;
        node->prev = current;
    }

}


void print(struct Node *head)
{
    struct Node *current = head;
    while(current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}


int length(struct Node *head)
{
    int len = 0;
    struct Node *current = head;
    while(current)
    {
        current = current->next;
        len++;
    }

    return len;
}

int Search(struct Node *head, int data, int length)
{
    struct Node *current = head;
    for(int i=0; i<length; i++)
    {
        if(current->data == data) return i;
        else current = current->next;
    }

    return -1;
}

void Delete(struct Node **head, int data)
{
    int idx = Search(*head, data, length(*head));
    struct Node *current = *head;
    for(int i=0; i<idx-1; i++)
    {
        current = current->next;
    }

    struct Node *deleteNode = current->next;
    current->next = deleteNode->next;
    deleteNode->next->prev = current;
    delete deleteNode;
    return;
}

int main()
{
    struct Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 25);
    push(&head, 35);
    push(&head, 5);
    push(&head, 7);
    print(head);
    cout << "Length : " << length(head) << "\n";
    cout << "10 is at : " << Search(head,10,length(head)) << "\n";
    cout << "12 is at : " << Search(head,12,length(head)) << "\n";
    Delete(&head, 10);
    print(head);
    cout << "10 is at : " << Search(head,10,length(head)) << "\n";
    
}
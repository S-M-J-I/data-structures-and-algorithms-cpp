#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *nextNode;
};

void insertFirst(struct Node *head, int n)
{
    //if the list is empty
    if (head == NULL)
    {
        //create a new node
        Node *node = new Node();
        //assign data to node data
        node->data = n;
        //make it point to itself
        node->nextNode = node;
        // make it head
        head = node;
        //end function
        return;
    }

    // create a node
    Node *node = new Node();
    // assign the last node as head -> this is used to traverse the loop
    Node *last = head;
    //assign the data
    node->data = n;
    // assign the nextNode of node as head node
    node->nextNode = head;
    // do
    do
    {
        // update loop
        last = last->nextNode;
        // until the nxt node of last node is the head node
    } while (last->nextNode != head);
    // assign node as head node
    head = node;
    // assign the nextnode of last node as head -> making it circular
    last->nextNode = head;
}

void print(struct Node *head)
{
    struct Node *current = head;
    do
    {
        cout << current->data << " -> ";
        current = current->nextNode;
    } while (current->nextNode != head);
    cout << current->data << "(head again)\n";
}

int main()
{

    struct Node *head = NULL;
    insertFirst(head, 10);
    insertFirst(head, 10);
    insertFirst(head, 10);
    insertFirst(head, 10);
    insertFirst(head, 10);
    insertFirst(head, 10);
    print(head);
}
#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;
};

class DoubleLinkedList
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;

public:
        
    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int data)
    {
        //create a new node
        Node *node = new Node();
        //set data to nodes data
        node->data = data;
        //if list is empty
        if(isEmpty())
        {
            // set nodes next as null
            node->next = NULL;
            // set nodes previous as null
            node->previous = NULL;
            // set the head and tail as node
            head = tail = node;
            //increase size
            size++;
            return;
        }

        // set heads previous to node
        head->previous = node;
        //set nodes nnext to point at head
        node->next = head;
        // set nodes previous to point at NULL
        node->previous = NULL;
        // make node the new head
        head = node;
        // increase size
        size++;
    }

    void append(int data)
    {
        // create a new node
        Node *node = new Node();
        // assign the data
        node->data = data;
        //if list is empty
        if(isEmpty())
        {
            // assign the node as head & tail of the list
            tail = head = node;
            // increase size
            size++;
            return;
        }
        
        // set nextnode of node as null
        node->next = NULL;
        // set the previous of node as tail
        node->previous = tail;
        // make current tails next node point to node
        tail->next = node;
        // finally make the node as the tail
        tail = node;
        // increase size
        size++;
    }

    void insertAt(int data, int index)
    {
        // if empty or Out Of Bounds
        if(isEmpty() || index <= 0 || index > size)
        {
            // push data
            push(data);
            return;
        }
        // create a node
        Node *node = new Node();
        // assign data to node data
        node->data = data;
        // assign head to current node -> used for traversing
        Node *current = head;
        // for i-> index-1
        for(int i=1; i<index-1; i++)
        {
            // keep shifting current node next
            current = current->next;
        }

        // set the next node of node to current's next node 
        node->next = current->next;
        // set the previous node of node as current
        node->previous = current;
        // if the next node of current has a value/exists 
        if(current->next)
        {   
            // make the previous node of the next node of current point to node 
            current->next->previous = node;
        }
        // currents next node points to node
        current->next = node;
        // increase size
        size++;
    }

    void pop()
    {
        // if list is empty, dont remove
        if(isEmpty())
        {
            cout << "Can't remove. List empty\n";
            return;
        }
        // assign remove to head
        Node *remove = head;
        // if head points to NULL
        if(head->next == NULL)
        {
            // make the tail NULL
            tail = NULL;
        }
        else //else
        {
            // set the previous of the next node head is pointing to as NULL
            head->next->previous = NULL; 
        }
        // set head to next node
        head = head->next;
        //decrease size
        size--;
        //make remove point to null
        remove->next = NULL;
        // free memory
        delete remove;
    }

    void removeLast()
    {
        //if list is empty
        if(isEmpty())
        {
            //dont delete
            cout << "Can't remove. List empty\n";
            return;
        }

        // assign node to remove as tail
        Node *remove = tail;
        //if the previous node of tail is null
        if(tail->previous == NULL)
        {
            // make the head null
            head = NULL;
        }
        else
        {
            // else set the next node of tails previous node as null
            tail->previous->next = NULL;
        }

        // shift tail back
        tail = tail->previous;
        // decrease size
        size--;
        // make removes previous point to null
        remove->previous = NULL;
        // delete remove and free memory
        delete remove;
    }

    void popAt(int index)
    {
        // if list is empty
        if(isEmpty())
        {
            // dont't delete
            cout << "List empty can't delete\n"; 
            return;
        }
        else if(index > size || index <= 0) // if index out of bounds
        {
            // remove from first
            pop();
            return;
        }
        // create a node to remove
        Node *remove = new Node();
        // and current to traverse the list
        Node *current = head;
        // for i 0->index-1 , traverse and shift the current node
        for(int i=1; i<index-1; i++)
        {
            current = current->next;
        }
        // the next node of the current node is the node we want to remove
        remove = current->next;
        // we want to link the next node of currentnode to the next next node u.e node after remove node 
        current->next = current->next->next;
        // set the node after remove node's previous to the current node
        current->next->previous = current;
        // decrease size
        size--;
        // destroy the link between the next and previous of remove node
        remove->next = remove->previous = NULL;
        // delete and free up memory
        delete remove;
    }

    int peek()
    {
        return head->data;
    }

    void display()
    {
        cout << "Double Linked List (Forward) : ";
        Node *current = head;
        cout << "NULL";
        while(current != NULL)
        {
            cout << " <- " << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    int getSize()
    {
        return this->size;
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    DoubleLinkedList list = DoubleLinkedList();
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);
    list.push(50);
    list.push(60);

    list.display();
    cout << "Peek : " << list.peek() << "\tSize : " << list.getSize() << endl;

    list.append(80);

    list.display();
    cout << "Peek : " << list.peek() << "\tSize : " << list.getSize() << endl;

    list.pop();
    list.display();
    cout << "Peek : " << list.peek() << "\tSize : " << list.getSize() << endl;

    list.removeLast();
    list.display();
    cout << "Peek : " << list.peek() << "\tSize : " << list.getSize() << endl;

    list.insertAt(15,3);
    list.display();
    
    cout << "Peek : " << list.peek() << "\tSize : " << list.getSize() << endl;

    list.popAt(3);
    list.display();
    
    cout << "Peek : " << list.peek() << "\tSize : " << list.getSize() << endl;
    
}
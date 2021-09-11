#ifndef Queues_h
#define Queues_h

#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
}; 

class Queue
{
public:
    Node *front, *rear;
    
    Queue(){
        this->front = NULL;
        this->rear = NULL;
    }

    void enqueue(int x)
    {
        struct Node *t;
        t = (struct Node *)malloc(sizeof(struct Node));
        if (t == NULL)
            printf("Queue is FUll\n");
        else
        {
            t->data = x;
            t->next = NULL;
            if (front == NULL)
                front = rear = t;
            else
            {
                rear->next = t;
                rear = t;
            }
        }
    }

    int dequeue()
    {
        int x = -1;
        struct Node *t;
        if (front == NULL)
            printf("Queue is Empty\n");
        else
        {
            x = front->data;
            t = front;
            front = front->next;
            free(t);
        }
        return x;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

};

class Stack
{
public:
    Node *top;

    Stack()
    {
        this->top = NULL;
    }

    bool isEmpty()
    {
        return this->top == NULL;
    }

    void push(int data)
    {
        Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = data;
        n->next = top;
        top = n;
    }

    int pop()
    {
        int x = -1;
        if(isEmpty())
        {
            printf("Stack empty\n");
        }
        else
        {
            Node *delNode = this->top;
            top = top->next;
            x = delNode->data;
            delete delNode;
        }

        return x;
    }


};

#endif
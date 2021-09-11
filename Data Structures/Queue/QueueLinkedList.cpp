#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL, *back = NULL;

void enqueue(int x)
{
    struct Node *t = new Node();
    if(t == NULL)
    {
        cout << "Queue Full\n";
        return;
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
        {
            front = back = t;
        }
        else
        {
            back->next = t;
            back = t;
        }
    }
}


int dequeue()
{
    int x = -1;
    struct Node *t;
    if(front==NULL)
    {
        cout << "Queue Empty\n";
    }
    else
    {
        t = front;
        front = front->next;
        x = t->data;
        delete t;
    }

    return x;
}


void printQueue()
{
    struct Node *t = front;
    while(t)
    {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL\n";
}

void reverse()
{
    stack<int> stk;
    while(front!=NULL)
    {
        stk.push(dequeue());
    }
    while(!stk.empty())
    {
        int x = stk.top();
        enqueue(x);
        stk.pop();
    }
}

int getSize()
{
    int len = 0;
    struct Node *p = front;
    while(p)
    {
        len++;
        p = p->next;
    }

    return len;
}

void sortQueue()
{
    
}


int main()
{
    enqueue(10);
    enqueue(30);
    enqueue(70);
    enqueue(20);
    enqueue(30);
    enqueue(10);
    enqueue(70);
    enqueue(40);
    enqueue(50);

    printQueue();

    dequeue();
    printQueue();

    reverse();
    printQueue();

    sortQueue();
    printQueue();
    
}
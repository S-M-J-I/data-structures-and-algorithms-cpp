#include <bits/stdc++.h>

using namespace std;

struct Queue
{
    int size;
    int front;
    int back;
    int *Q;
};

bool isEmpty(struct Queue q){return q.front==q.back;}

bool isFull(struct Queue q){return q.back==q.size-1;}

void enqueue(struct Queue *q, int x)
{
    if(isFull(*q))
    {
        cout << "Queue is full\n";
        return;
    }

    q->back++;
    q->Q[q->back] = x;
}

int dequeue(struct Queue *q)
{
    if(isEmpty(*q))
    {
        cout << "Queue is empty\n";
        return -1;
    }

    q->front++;
    int x = q->Q[q->front];
    return x;
}


int getFront(struct Queue q) {return q.Q[q.front+1];}
int getBack(struct Queue q) {return q.Q[q.back];}

void resetPointers(struct Queue *q)
{
    if(isEmpty(*q) && isFull(*q))
    {
        q->front = q->back = -1;
    }
}

void printQueue(struct Queue q)
{
    cout << "Queue : ";
    for(int i=q.front+1; i<=q.back; i++)
    {
        cout << q.Q[i] << " -> ";
    }
    cout << "\n";
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    struct Queue q;
    int n = 7;
    q.size = n;
    q.Q = new int[q.size];
    q.front = q.back = -1;



    for(int i=0; i<q.size; i++)
    {
        enqueue(&q,(i+1));
    }
    printQueue(q);
    cout << "Front : " << getFront(q) << "\tBack : " << getBack(q) << "\n";



    for(int i=0; i<2; i++)
    {
        dequeue(&q);
    }
    printQueue(q);
    cout << "Front : " << getFront(q) << "\tBack : " << getBack(q) << "\n";


}
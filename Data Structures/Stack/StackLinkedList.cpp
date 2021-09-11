#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    int size = 0;
    struct Node *next;
}*top=NULL;


void push(int x)
{
    struct Node *t = new Node();
    if(t==NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    t->data = x;
    t->next = top;
    top = t;
    t->size++;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    else{
        Node *p;
        p = top;
        top = top->next;
        int x = p->data;
        delete p;
        return x;
    }
    
}

int topElement()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return top->data;
    }
}

int peek(int pos)
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }

    Node *p = top;
    for(int i=1; i<pos; i++){
        p = p->next;
        if(p->next==NULL)
        {
            printf("Not found\n");
            return -1;
        }
    }

    return p->data;
}

void display()
{
    struct Node *p;
    p = top;
    printf("Stack : \n");
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(40);
    push(30);
    push(70);
    
    display();
    cout << "Top : " << topElement() << endl;
    cout << "Peek @ 3 : " << peek(3) << endl;

    pop();
    pop();

    display();
    cout << "Top : " << topElement() << endl;
    cout << "Peek @ 4 : " << peek(4) << endl;
}
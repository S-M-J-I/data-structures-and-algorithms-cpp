#include <bits/stdc++.h>

using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;  
};

bool isFull(struct Stack stk){return stk.top == stk.size-1;}
bool isEmpty(struct Stack stk){return stk.top == -1;}

void push(struct Stack *stk, int x)
{
    if(isFull(*stk))
    {
        cout << "Stack full\n";
        return;
    }

    stk->top++;
    stk->s[stk->top] = x;
}

int pop(struct Stack *stk)
{
    if(isEmpty(*stk))
    {
        cout << "Stack empty\n";
        return -1;
    }

    int x = stk->s[stk->top];
    stk->top--;
    return x;
}

void enqueue(struct Stack *s1, int x)
{
    push(s1,x);
}


int dequeue(struct Stack *s1, struct Stack *s2)
{
    for(int i=s1->top; i>=0 ; i--)
    {
        push(s2,pop(s1));
    }


    return pop(s2);
}


void print(struct Stack stk)
{
    cout << "Stack : \n";
    if(isEmpty(stk))
    {
        cout << "Stack is empty\n";
        return;
    }

    for(int i=stk.top; i>=0; i--)
    {
        cout << stk.s[i] << "\n";
    }
}


int main()
{
    struct Stack s1,s2;
    s1.size = s2.size = 7;
    s1.top = s2.top = -1;
    s1.s = new int[s1.size];
    s2.s = new int[s2.size];

    enqueue(&s1,6);
    enqueue(&s1,3);
    enqueue(&s1,9);
    enqueue(&s1,5);

    print(s1);

    cout << "Dequeue : " << dequeue(&s1,&s2) << endl;
    print(s1);
    print(s2);
    cout << "Dequeue : " << dequeue(&s1,&s2) << endl;
    print(s1);
    print(s2);

}
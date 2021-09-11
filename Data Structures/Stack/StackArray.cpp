#include<bits/stdc++.h>

using namespace std;


struct Stack
{
    int size;
    int top;
    int *s;
};


bool isEmpty(struct Stack stk)
{
    return stk.top == -1;
}


bool isFull(struct Stack stk)
{
    return stk.top == stk.size-1;
}


void push(struct Stack *stk, int x)
{
    if(isFull(*stk))
    {
        printf("Stack Overflow for value %d\n", x);
        return;
    }

    
    stk->s[++stk->top] = x;
}


int pop(struct Stack *stk)
{
    if(isEmpty(*stk))
    {
        cout << "Stack Underflow\n";
        return -1;
    }

    int x = stk->s[stk->top--];
    return x;
}


int top(struct Stack stk)
{
    return stk.s[stk.top];
}


int peek(struct Stack stk, int pos)
{
    if(isEmpty(stk))
    {
        printf("No elements in stack\n");
        return -1;
    }

    return stk.s[stk.top - pos + 1];
}


void display(struct Stack stk)
{
    printf("Stack : \n");
    for(int i=stk.top; i>=0; i--)
    {
        printf("%d\n", stk.s[i]);
    }
}


int main()
{
    struct Stack stk;
    int n; scanf("%d", &n);
    stk.size = n;
    stk.s = new int[stk.size];
    stk.top = -1;

    push(&stk,12);
    push(&stk,13);
    push(&stk,87);
    push(&stk,24);
    push(&stk,28);
    push(&stk,84);
    display(stk);
    cout << "Top : " << top(stk) << endl;

    pop(&stk);
    pop(&stk);
    
    
    display(stk);
    cout << "Top : " << top(stk) << endl;

    cout << "Peek at 3 : " << peek(stk,3) << endl;
}
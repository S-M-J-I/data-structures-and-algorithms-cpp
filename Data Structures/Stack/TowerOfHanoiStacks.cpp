#include <bits/stdc++.h>

using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

struct Stack *createStack(int size);
void push(struct Stack *stk, int x);
int pop(struct Stack *stk);
void tower(int disks, struct Stack *source, struct Stack *inter, struct Stack *dest);

int main()
{
    // number of disks
    int n = 3;
    // three stacks
    struct Stack *source, *inter, *dest;

    // create stacks
    source = createStack(n);
    inter = createStack(n);
    dest = createStack(n);

    tower(n, source, inter, dest);

    delete source, inter, dest;
}

// METHOD FOR CREATING THE STACKS
struct Stack *createStack(int size)
{
    struct Stack *stk;
    stk->size = size;
    stk->s = new int[stk->size];
    stk->top = -1;

    return stk;
}

bool isEmpty(struct Stack stk)
{
    return stk.top == -1;
}

bool isfull(struct Stack stk)
{
    return stk.size == stk.top - 1;
}

void push(struct Stack *stk, int x)
{
    if (stk->size == stk->top - 1)
    {
        cout << "Stack Overflow";
        return;
    }

    stk->top++;
    stk->s[stk->top] = x;
}

int pop(struct Stack *stk)
{
    if (stk->top == -1)
    {
        return -1;
    }

    int x = stk->s[stk->top];
    stk->top--;
    return x;
}


void move(int disk, char from_Rod, char to_Rod)
{
    cout << "Move " << disk << " from " << from_Rod << " to " << to_Rod << "\n";
}


void moveDisk(struct Stack *source, struct Stack *dest, char s, char d)
{
    int topS = pop(source);
    int topD = pop(dest);
 
    if(topS == -1)
    {
        push(source, topD);
        move(topD,d,s);
    }
    else if(topD == -1)
    {
        push(dest,topS);
        move(topS,s,d);
    }
    else if(topS > topD)
    {
        push(source, topS);
        push(source, topD);
        move(topD,s,d);
    }
    else
    {
        push(dest, topD);
        push(dest, topS);
        move(topS,s,d);
    }
}

void tower(int disks, struct Stack *source, struct Stack *inter, struct Stack *dest)
{
    char S = 'S', I = 'A', D = 'D';

    if(disks % 2 == 0)
    {
        char temp = D;
        D = I;
        I = temp;
    }

    for(int i=disks; i>=1; i--)
    {
        push(source,i);
    }

    for (int i = 1; i <= pow(2,disks) - 1; i++)
    {
        
        if (i % 3 == 1)
        {
            moveDisk(source,dest,S,D);
        }
        else if (i % 3 == 2)
        {
            moveDisk(source,inter,S,I);
        }
        else if (i % 3 == 0)
        {
            moveDisk(inter,dest,I,D);
        }
    }
}
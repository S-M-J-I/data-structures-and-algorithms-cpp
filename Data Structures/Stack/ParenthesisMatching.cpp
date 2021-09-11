#include<bits/stdc++.h>

using namespace std;

struct Stack
{
    int size;
    int top;
    char *s;
};

bool isEmpty(struct Stack stk)
{
    return stk.top == -1;
}

bool isFull(struct Stack stk)
{
    return stk.top == stk.size - 1;
}

void push(struct Stack *stk, char c)
{
    stk->top++;
    stk->s[stk->top] = c;
}

char pop(struct Stack *stk)
{
    char c = stk->s[stk->top];
    stk->top--;
    return c;
}


int isBalanced(string str)
{
    Stack stk;
    stk.size = str.length();
    stk.top = -1;
    stk.s = new char[stk.size];

    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
        {
            push(&stk,str[i]);
        }
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if(isEmpty(stk))
            {
                return false;
            }
            else
            {
                pop(&stk);
            }
        }
    }

    return (isEmpty(stk)) ? true : false;
}

int main()
{
    string str = "[{{({})([])})]";
    int res = isBalanced(str);

    switch (res)
    {
    case 1:
        cout << "Balanced Parenthesis\n";
        break;
    
    case 0:
        cout << "Not Balanced Parenthesis\n";
        break;
    }
}
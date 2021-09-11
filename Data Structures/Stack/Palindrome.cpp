#include <bits/stdc++.h>

using namespace std;

struct Stack
{
    int size;
    int top;
    char *s;
};

bool isFull(struct Stack stk)
{
    return stk.size == stk.top-1;
}

bool isEmpty(struct Stack stk)
{
    return stk.top == -1;
}


void push(struct Stack *stk, char ch)
{
    if(isFull(*stk))
    {
        cout << "Stack is Full\n";
        return;
    }

    stk->top++;
    stk->s[stk->top] = ch;
}

char pop(struct Stack *stk)
{
    if(isEmpty(*stk))
    {
        cout << "Stack is Empty\n";
        return -1;
    }

    char c = stk->s[stk->top];
    stk->top--;
    return c;
}

bool isPalindrome(string str1, string str2)
{
    return str1 == str2;
}

int main()
{
    string chars; 
    cin >> chars;
    struct Stack stk;
    stk.size = chars.size();
    stk.top = -1;
    stk.s = new char[stk.size];

    for(int i=0; i<chars.size(); i++)
    {
        push(&stk,chars[i]);
    }

    string BackwardChar;

    while(!isEmpty(stk))
    {
        BackwardChar.push_back(pop(&stk));
    }

    switch (isPalindrome(chars,BackwardChar))
    {
    case true:
        cout << "Is Palindrome\n";
        break;
    
    case false:
        cout << "Is not a Palindrome\n";
        break;
    }

    
}
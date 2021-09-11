#include<bits/stdc++.h>

using namespace std;

struct Node{
    char data;
    struct Node *next; 
}*top = NULL;

void push(char ch){
    struct Node *t = new Node();
    
    t->data = ch;
    t->next = top;
    top = t;
}

char pop(){
    if(top==NULL){
        cout << "Stack is empty\n";
        return -1;
    }else {
        struct Node *t = top;
        char x = t->data;
        top = top->next;
        delete t;
        return x;
    }
}

void Display(){
    struct Node *t = top;
    while(t){
        cout << "t";
        t = t->next;
    }
    cout << "\n";
}

int isBalanced(char *expr){
    for(int i=0; expr[i]!='\0'; i++) {

        if( expr[i] == '(' ){
            push(expr[i]);
        }else if ( expr[i] == ')' ) {
            
            if(top == NULL){
                return 0;
            }

            pop();
        }
    }

    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}


int pre(char ch){
    // if character is + or -, it is 1
    if(ch == '+' || ch == '-'){
        return 1;
    }else if (ch == '*' || ch == '/'){
        return 2;
    }

    return 0;
}

int isOperand(char ch){
    // if operator then 0
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 0;
    }

    return 1;
}


char * InfixToPostfix(char *infix){
    
    // i to track infix and j to track postfix
    int i = 0, j = 0;
    char *postfix;
    // find length of infix
    int len = strlen(infix);
    // declare postfix expr
    postfix = new char[len];

    // while infix is not read until last character
    while(infix[i] != '\0'){
        // check if operand, if so add to postfix
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }else{
            // else check if infix[i] is greater than top of stack, if yes, then push to stack
            if(pre(infix[i]) > pre(top->data)){
                push(infix[i++]);
            }else{
                // else pop from stack and add to postfix
                postfix[j++] = pop(); 
            }
        }
    }

    // if anything remains, pop and add to postfix
    while(top != NULL){
        postfix[j++] = pop();
    }
    // make last value of postfix as NULL character
    postfix[j] = '\0';

    // return the expression
    return postfix;
}


int main()
{
    char *infix = "a+b*c-d/e";
    // in the InfixToPostfix method while checking predecence, empty stack may throw an error so initialse with #
    push('#');

    char *postfix = InfixToPostfix(infix);

    printf("%s\n", postfix);
}
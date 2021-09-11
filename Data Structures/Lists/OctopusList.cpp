#include <bits/stdc++.h>

using namespace std;

// Node for LL
struct Node
{
    int data;
    struct Node *next;
};

// create the dummy head
// head will have 4 node, which will act as the heads of left, right, top, bottom list
struct Head
{
    int dummyVal;
    struct Node *left;
    struct Node *right;
    struct Node *top;
    struct Node *bottom;

} * head = NULL;

// create the head
Head * createHead()
{
    struct Head *head = new Head();

    head->dummyVal = 1;
    head->bottom = NULL;
    head->left = NULL;
    head->top = NULL;
    head->right = NULL;

    return head;
}

// push inside the list based on the operation
void push(char op, int data)
{
    // create a node, add to data
    struct Node *node = new Node();
    node->data = data;

    /***Naming Condition:
     
        T for top
        B for bottom
        L for left
        R for right
    */

    // if operation is T
    if (op == 'T')
    {
        // if top's head is null
        if (head->top == NULL)
        {
            head->top = node;
            return;
        }
        // store the head of the list head.
        struct Node *store = head->top;
        // point the head of the list to the node
        head->top = node;
        // point the next node to store
        node->next = store;
    }
    else if (op == 'B')
    {
        if (head->bottom == NULL)
        {
            head->bottom = node;
            return;
        }
        struct Node *store = head->bottom;
        head->bottom = node;
        node->next = store;
    }
    else if (op == 'L')
    {
        if (head->left == NULL)
        {
            head->left = node;
            return;
        }
        struct Node *store = head->left;
        head->left = node;
        node->next = store;
    }
    else if (op == 'R')
    {
        if (head->right == NULL)
        {
            head->right = node;
            return;
        }
        struct Node *store = head->right;
        head->right = NULL;
        head->right = node;
        node->next = store;
    }

    return;
}

// print the lists
void PrintList(Node *node){
    struct Node *p = node;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}


// print the lists sum, pass the list's head as the indicator of where we would sum up
int ListSum(Node *node)
{
    struct Node *p = node;
    int sum = 0;

    while (p)
    {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

// print the maximum list with sum
void printMaxofLists(int condition, int max){

    /***INDICATOR:
        0 - top
        1 - right
        2 - left
        3 - bottom
    */

    switch (condition)
    {
        case 0:
        {
            cout << "Top Linked List Has Maximum Sum " << max << "\n";
            break;
        }
        case 1:
        {
            cout << "Right Linked List Has Maximum Sum " << max << "\n";
            break;
        }
        case 2:
        {
            cout << "Left Linked List Has Maximum Sum " << max << "\n";
            break;
        }
        case 3:
        {
            cout << "Bottom Linked List Has Maximum Sum " << max << "\n";
            break;
        }
    }

}

int main()
{
    // create head
    head = createHead();

    // take an input, and push values
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char opt;
        cin >> opt;
        int data;
        cin >> data;
        push(opt, data);
    }

    // TESTCASES : Display the lists
    PrintList(head->top);
    PrintList(head->right);
    PrintList(head->left);
    PrintList(head->bottom);

    // here, we store the sum of the lists
    int sum[4];

    /***INDICATOR:
        0 - top
        1 - right
        2 - left
        3 - bottom
    */

    // store in the specified index as per stated above
    sum[0] = ListSum(head->top);
    sum[1] = ListSum(head->right);
    sum[2] = ListSum(head->left);
    sum[3] = ListSum(head->bottom);

    // search for max in all lists
    int max = sum[0];
    int idx = 0;
    for (int i = 0; i < 4; i++)
    {
        if (sum[i] > max)
        {
            max = sum[i];
            idx = i;
        }
    }


    // query the index
    printMaxofLists(idx, max);

}

#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class Node
{
    public:
    int data;
    Node *nextNode;
};

class LinkedList
{
    public:
    Node *head = NULL;
    int size = 0;

    bool isEmpty()
    {
        return head == NULL;
    }

    // ADD NODE TO FRONT OF LL
    void push(int n)
    {
        // 1. create a new node
        Node *node = new Node();

        // 2. add tha data
        node->data = n;

        // 3. make the new node point to head as the next node
        node->nextNode = head;

        // 4. then make the new node as head of the linked list
        head = node;
        size++;
    }

    // ADD NODE TO BACK OF LL
    void append(int data)
    {
        // 1. create a new node
        Node *node = new Node();

        // 2. use this node to traverse the LL upto last
        Node *lastNode = head;
        // 3. assign the data to new node data
        node->data = data;
        //set the next node of new node to NULL, as it'll be added last
        node->nextNode = NULL;

        //if the LL is empty, then make new node the head of LL
        if (isEmpty())
        {
            head = node;
            size++;
            return;
        }

        //else use lastNode to traverse the list until it reaches the end
        while (lastNode->nextNode != NULL)
        {
            lastNode = lastNode->nextNode;
        }

        //when it does, assign the next node of the last node present to new node
        lastNode->nextNode = node;
        //increase list size
        size++;
        //return nothing
        return;
    }

    void addAt(int data, int position)
    {
        //CHECK IF POSITION IS VALID OR NOT
        if (position > size)
        {
            cout << "Position is greater than size of List! Adding to end\n";
            append(data);
            return;
        }
        else if (position < 0)
        {
            cout << "Position is not in range! Adding to start!\n";
            push(data);
            return;
        }
        else if (isEmpty())
        {
            push(data);
            return;
        }

        // 1. create a new node to add
        Node *node = new Node();

        // 3. set currentNode to head. this will be used for traversal
        Node *currentNode = head;
        // 4. set finder as 1. No need to start from 0 as 0 is head
        int finder = 0;
        // 5. keep traversing until currentNode is not null
        while (currentNode != NULL)
        {
            //increment finder
            finder++;
            //if its equal to position
            if (finder == position)
            {
                node->nextNode = currentNode->nextNode;
                node->data = data;
                currentNode->nextNode = node;
                node->nextNode = (currentNode->nextNode)->nextNode;
                size++;
                break;
            }
            currentNode = currentNode->nextNode;
        }
    }

    // DELTE FROM FRONT OF LL
    void pop()
    {
        if (isEmpty())
        {
            cout << "Can't delete! List is empty!\n";
            return;
        }
        // 1. create the node to remove
        Node *remove = head;
        // 2. set head as its next node
        head = head->nextNode;
        // 3. decrease size
        size--;
        // 4. set the remove nodes next node as null
        remove->nextNode = NULL;
        // 5. finally, delete that pointer and free up memory
        delete remove;
    }

    void popAt(int position)
    {
        // if list is empty
        if (isEmpty())
        {
            cout << "Can't delete! List empty!\n";
            return;
        }

        // store head node
        Node *remove = head;

        if (position == 0)
        {
            head = remove->nextNode; //change head node
            free(remove);            // free old head
            size--;                  // decrease size
            return;
        }

        //find previous node of the node to be deleted
        for (int i = 0; remove != NULL && i < position - 1; i++)
        {
            remove = remove->nextNode;
        }

        // if position is more than number of nodes
        if (remove == NULL || remove->nextNode == NULL)
        {
            return;
        }

        // Node temp->next is the node to be deleted
        // Store pointer to the next of node to be deleted
        Node *next = remove->nextNode->nextNode;

        // Unlink the node from LL
        free(remove->nextNode); // free memory

        // unlink the deleted node from list
        remove->nextNode = next;
        size--; // decrease size
    }

    //Search
    int search(int val)
    {
        int index = -1;
        Node *currentNode = head;
        while (currentNode != NULL)
        {
            index++;
            if (val == currentNode->data)
            {
                return index;
            }

            currentNode = currentNode->nextNode;
        }

        return index;
    }

    void display()
    {
        Node *currentNode = head;
        while (currentNode != NULL)
        {
            cout << currentNode->data << " -> ";
            currentNode = currentNode->nextNode;
        }
        cout << "NULL\n";
    }

    int sum()
    {
        int total = 0;
        Node *currentNode = head;
        while (currentNode != NULL)
        {
            total += currentNode->data;
            currentNode = currentNode->nextNode;
        }

        return total;
    }

    int *toArray()
    {
        int *arr = new int[size];
        Node *node = head;
        for (int i = 0; i < size && node != NULL; i++, node = node->nextNode)
        {
            arr[i] = node->data;
        }

        return arr;
    }

    int middleElement()
    {
        int middle;
        int target = size / 2;
        Node *currentNode = head;
        for (int i = 0; i <= target && currentNode != NULL; i++, currentNode = currentNode->nextNode)
        {
            middle = currentNode->data;
        }

        return middle;
    }

    int peek()
    {
        return head->data;
    }

    int getLast()
    {
        Node *last = head;
        while (last != NULL)
        {
            last = last->nextNode;
        }

        return last->data;
    }

    void reverse()
    {
        Node *p = head;
        int a[size];

        int i = 0;
        while (p != NULL)
        {
            a[i] = p->data;
            p = p->nextNode;
            i++;
        }

        p = head;
        i--;
        for (; i >= 0; i--)
        {
            p->data = a[i];
            p = p->nextNode;
        }
    }

    void reverseWithPointer()
    {
        Node *p = head;
        Node *q = NULL;
        Node *r = NULL;

        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->nextNode;
            q->nextNode = r;
        }

        head = q;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LinkedList list = LinkedList();
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);

    list.display();

    list.append(90);

    list.display();
    cout << "Size of LL : " << list.size << "\n";

    list.pop();
    list.display();

    cout << "Size of LL : " << list.size << "\n";
    cout << "Middle Element of LL : " << list.middleElement() << "\n";

    list.addAt(15, 3);
    list.display();
    cout << "Size of LL : " << list.size << "\n";

    list.addAt(5, -3);
    list.display();
    cout << "Size of LL : " << list.size << "\n";

    list.addAt(15, 9);
    list.display();
    cout << "Size of LL : " << list.size << "\n";

    list.popAt(3);
    list.display();
    cout << "Size of LL : " << list.size << "\n";

    cout << list.search(90) << endl;

    cout << "Sum of all elements in LL : " << list.sum() << endl;

    cout << "Middle Element of LL : " << list.middleElement() << "\n";

    list.reverse();
    cout << "Reversed Linked List: ";
    list.display();

    cout << "Reversed Linked List: ";
    list.reverseWithPointer();
    list.display();
}
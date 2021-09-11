#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *nextNode;
};

class CircularLinkedList
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
        //if the list is empty
        if(isEmpty())
        {
            //create a new node
            Node *node = new Node();
            //assign data to node data
            node->data = n;
            //make it point to itself
            node->nextNode = node;
            // make it head
            head = node;
            //increase size
            size++;
            //end function
            return;
        }

        // create a node
        Node *node = new Node();
        // assign the last node as head -> this is used to traverse the loop
        Node *last = head;
        // assign the data
        node->data = n;
        // assign the nextNode of node as head node
        node->nextNode = head;
        // do 
        do{
            // update loop
            last = last->nextNode;
            // until the nxt node of last node is the head node
        }while( last->nextNode != head );
        // assign node as head node 
        head = node;
        // assign the nextnode of last node as head -> making it circular
        last->nextNode = head;
        // increase size
        size++;
    }

    void pushAt(int data, int index)
    {
        // if is empty or index is not in range
        if(isEmpty() || (index<=0 || size < index) )
        {
            //push in front
            push(data);
            //return nothing
            return;
        }

        // create a node
        Node *node = new Node();
        // assign data to node data
        node->data = data;
        // take a current node to traverse list
        Node *currentNode = head;
        for(int i=1; i<index-1; i++)
        {
            // keep updating the currentnode until before index
            currentNode = currentNode->nextNode;
        }
        // assign node of nextnode to current nextnode
        node->nextNode = currentNode->nextNode;
        // current nodes next node will be pointing at node
        currentNode->nextNode = node;
        // increase size
        size++;
    }

    void pop()
    {
        // assign head to remove node 
        Node *remove = head;
        // assign head to head
        Node *last = head;
        // keep updating the last node
        do{
            last = last->nextNode;
        }while ( last->nextNode != head ); // until the nextnode of last node is head

        // assign the next node as last node to the nextnode of remove node
        last->nextNode = remove->nextNode;
        // shift the head to its next node
        head = head->nextNode;
        //decrement size
        size--;
        // remove and free up memory
        delete remove;

    }

    void popAt(int index)
    {
        if(isEmpty() || (index<=0 || index>size))
        {
            pop();
            return;
        }
        // assign head to the node we want to remove
        Node *remove = new Node();
        // assign current node to the head -> used to iterate the linked list
        Node *currentNode = head;
        //for i=0 to 2 less than position
        for(int i=1; i<index-1; i++)
        {
            //keep shifting to next node
            currentNode = currentNode->nextNode;
        }
        // make remove node point to the next node of current node
        remove = currentNode->nextNode;
        // make current nodes next node point to the next node of remove node
        currentNode->nextNode = remove->nextNode;
        // delete remove and free up space
        delete remove;
        // decrease the size
        size--;
    }

    int search(int key)
    {
        // take current node as head -> iterate
        Node *current = head;
        // for 1 -> size && while currents nextnode is not equal to head node
        for(int i=1; i<=size && current->nextNode != head; i++)
        {
            //check for key value equality
            if(current->data == key)
            {
                //return index of true
                return i;
            }
            //else just update current and keep looking
            current = current->nextNode;
        }

        // if not found return -1
        return -1;
    }

    int sum()
    {
        int sum = 0;
        Node *node = head;
        do{
            sum += node->data;
            node = node->nextNode;
        }while( node != head );


        return sum;
    }

    void display()
    {
        Node *currentNode = head;
        if(!isEmpty())
        {
            do{        
                cout << currentNode->data << " -> ";
                currentNode = currentNode->nextNode;
            }
            while( currentNode != head );
        }
        cout << currentNode->data << "(head again)\n";
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    CircularLinkedList list = CircularLinkedList();
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);
    list.push(50);

    list.display();
    cout << "Size of list : " << list.size << endl;

    list.pushAt(15,3);

    list.display();

    cout << "Sum of list : " << list.sum() << endl;
    cout << "Size of list : " << list.size << endl;

    list.pop();

    list.display();

    cout << "Sum of list : " << list.sum() << endl;
    cout << "Size of list : " << list.size << endl;

    list.popAt(3);

    list.display();
    cout << "Size of list : " << list.size << endl;

    cout << "Element 15 at : " << list.search(15) << endl;
    cout << "Element 1 at : " << list.search(1) << endl;

}
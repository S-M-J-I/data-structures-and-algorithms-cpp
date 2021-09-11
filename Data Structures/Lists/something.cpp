#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
} *head = NULL, *tail = NULL;

void create()
{
    node *temp;
    int value;
    if (head == NULL)
    {
        head = new node();
        scanf("%d", &value);
        head->data = value;
        head->next = head;
        tail = head;
        /* The statement was previously head = tail,
            why didn't it work?
                A : because you created head, assigned a value to it, But tail was still null.
                    so head = tail, meant you were assigning TAIL TO HEAD. NULL TO A VALUE
                    THUS A LOOPHOLE FORMED WHERE HEAD WAS ALWAYS REPLACED BY NULL
        */
    }

    else if (head != NULL)
    {

        temp = new node();
        scanf("%d", &value);
        temp->data = value;
        if (temp->data >= tail->data)
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            tail->next = head;
        }
        // missed condition #1 : if data entered is less than head 
        else if (temp->data <= head->data)
        {
            // reset the pointers
            temp->next = head; // 1 : point temp's next to head
            temp->next->prev = temp; // 2 :  point the temp's next previous (basically head) to temp
            temp->prev = tail; // 3 : point temp's previous to tail
            tail->next = temp; // 4 : point tails next to temp
            head = temp; // 5 : make temp the new head
        }
        else if (temp->data < tail->data)
        {
            node *temp1 = head;
            // (1) if you compare with temp1->data, then in cases like 15 between 10 and 20 wont work
            /* always make sure the node you want to work with while inserting into middle of LLs are always one node behind the position 
                you want to insert

                therefore, compare temp data with the data of temp1's next node
            */ 
            while (temp->data > temp1->next->data && temp1->next != NULL) // ALWAYS ALWAYS ALWAYS CHECK FOR NULL IN A NODE
            {
                temp1 = temp1->next;
            }
            // (2) point temps next to temp1's next node
            temp->next = temp1->next;
            // (3) if temp1 has a next node i.e temp1->next is not NULL
            if (temp1->next != NULL)
            {
                // point temp's next's previous to temp
                temp->next->prev = temp;
            }
            // (4) if we are at the last node, i.e temp->next is NULL
            else
            {
                // make temp the tail
                tail = temp;
            }
            // rearrange the pointers
            // make temp1's next point to temp
            temp1->next = temp;
            // and temp's previous point to temp1
            temp->prev = temp1;
        }
    }

    printf("inserted %d into LL\n", temp->data);
}

void display()
{
    node *temp;
    temp = head;
    printf("Linked List:  ");

    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void search(int item)
{
    node *temp;
    temp = head;
    do
    {
        if (item == temp->data)
        {
            printf("%d is found\n", item);
            break;
        }
        else
        {
            temp = temp->next;
        }
    } while (temp != head);
    if (temp == head)
    {
        printf("%d not found\n", item);
    }
}
void Delete(int item)
{
    node *temp;
    temp = head;
    do
    {
        if (item == temp->next->data)
        {
            temp->next = temp->next->next;
            node *temp1 = temp->next->next;
            temp1->prev = temp;
            break;
        }
        else
        {
            temp = temp->next;
        }
    } while (temp != head);
    if (temp == head)
    {
        printf("%d not found\n", item);
    }
}

void length()
{

    node *temp;
    temp = head->next;
    int count = 1;
    while (temp != head)
    {
        count++;
        temp = temp->next;
    }
    printf("The length of the linked list is  %d\n", count);
}

int main()
{
    int ans;
    do
    {
        printf("Add item to the linked list? 1/0 \n");
        scanf("%d", &ans);
        if (ans == 0)
        {
            break;
        }
        create();
    } while (ans == 1);

    display();
    search(10);
    length();
    Delete(30);
    display();
    return 0;
}
#include<bits/stdc++.h>

using namespace std;


class Person
{
    private:
    string name;
    int id;

    public:
    Person(string name, int id)
    {
        this->name = name;
        this->id = id;
    }

    void getDetails()
    {
        cout << "{Name : " << this->name << " | ID : " << this->id << "} -> ";
    }
};


class Node
{
    public:
    Person person;
    Node *nextNode;
};


class LinkedList
{
    public:
    Node *head = NULL;
    int size = 0;

    void addEmployee(Person person)
    {
        Node *node;
        node->person = person;
        node->nextNode = head;
        head = node;
    }

    void deleteEmployee()
    {
        Node *node;
        node = head;
        head = head->nextNode;
        delete node;
    }

    void printList()
    {
        Node *p = head;
        cout << "\nEMPLOYEES : \n";
        while(p != NULL)
        {
            p->person.getDetails();
            p = p->nextNode;
        }
        cout << "END OF LIST\n";
    }
};



int main()
{
    LinkedList list = LinkedList();
    list.addEmployee(Person("Jishan",11));
    list.addEmployee(Person("Sayere",21));
    list.addEmployee(Person("Shamir",42));
    list.printList();
    list.deleteEmployee();
    list.printList();
}